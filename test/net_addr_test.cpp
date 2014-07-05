#include "gtest/gtest.h"
#include "utils.h"
#include "net_addr.h"
#include <sys/endian.h>
#include <algorithm>

using namespace std;

static const int net_addr_size = 30;

TEST (net_addr, v4_magic)
{
  const uint32_t time = 0x1a2b3c4d;
  const uint64_t services = 0x1a2b00003c4d;
  const uint32_t ip = 0xc0a80001;
  const uint16_t port = 0x208d;  

  uint8_t expected[net_addr_size]; 
  int offset = 0;

  uint32_t time_le = htole32 (time);
  uint8_t *time_le_bytes = reinterpret_cast<uint8_t *> (&time_le);
  copy (time_le_bytes, time_le_bytes + sizeof (time), expected + offset);
  offset += sizeof (time);

  uint64_t services_le = htole64 (services);
  uint8_t *services_le_bytes = reinterpret_cast<uint8_t *> (&services_le);
  copy (services_le_bytes, services_le_bytes + sizeof (services), expected + offset);
  offset += sizeof (services);

  uint32_t ip_be = htobe32 (ip);
  uint8_t *ip_be_bytes = reinterpret_cast<uint8_t *> (&ip_be);
  fill_n (expected + offset, 12, 0);
  offset += 12;
  copy (ip_be_bytes, ip_be_bytes + sizeof (ip), expected + offset);
  offset += sizeof (ip);

  uint16_t port_be = htobe16 (port);
  uint8_t *port_be_bytes = reinterpret_cast<uint8_t *> (&port_be);
  copy (port_be_bytes, port_be_bytes + sizeof (port), expected + offset);

  is_equal (net_addr::build_v4 (time, services, ip, port).serialise (), expected, net_addr_size);
}

TEST (net_addr, v6_magic)
{
  const uint32_t time = 0x1a2b3c4d;
  const uint64_t services = 0x1a2b00003c4d;

  /* Build an ipv6 address */
  uint8_t ip[net_addr::ipv6_size];
  uint64_t ip_upper = 0x114a76fe;
  uint64_t ip_lower = 0xe7b81ad0;
  uint8_t *ip_upper_bytes = reinterpret_cast<uint8_t *> (&ip_upper);
  uint8_t *ip_lower_bytes = reinterpret_cast<uint8_t *> (&ip_lower);
  copy (ip_upper_bytes, ip_upper_bytes + sizeof (uint64_t), ip);
  copy (ip_lower_bytes, ip_lower_bytes + sizeof (uint64_t), ip + sizeof (uint64_t));

  const uint16_t port = 0x208d;  

  uint8_t expected[net_addr_size]; 
  int offset = 0;

  uint32_t time_le = htole32 (time);
  uint8_t *time_le_bytes = reinterpret_cast<uint8_t *> (&time_le);
  copy (time_le_bytes, time_le_bytes + sizeof (time), expected + offset);
  offset += sizeof (time);

  uint64_t services_le = htole64 (services);
  uint8_t *services_le_bytes = reinterpret_cast<uint8_t *> (&services_le);
  copy (services_le_bytes, services_le_bytes + sizeof (services), expected + offset);
  offset += sizeof (services);

  copy (ip, ip + net_addr::ipv6_size, expected + offset);
  offset += net_addr::ipv6_size;

  uint16_t port_be = htobe16 (port);
  uint8_t *port_be_bytes = reinterpret_cast<uint8_t *> (&port_be);
  copy (port_be_bytes, port_be_bytes + sizeof (port), expected + offset);

  is_equal (net_addr::build_v6 (time, services, ip, port).serialise (), expected, net_addr_size);
}
