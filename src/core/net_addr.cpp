#include "net_addr.h"
#include "portable_endian.h"
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<uint8_t>
net_addr::serialise () const 
{
  // All integers serialised little-endian, except IP and port which use network
  // order (big endian)
  int length = 30;

  // Build serialised representation first in uint8_t buffer, then return as
  // vector
  uint8_t buffer[length];
  int offset = 0;

  uint32_t time_le = htole32 (time);
  memcpy (buffer + offset, &time_le, sizeof (uint32_t));
  offset += sizeof (uint32_t);

  uint64_t services_le = htole64 (services);
  memcpy (buffer + offset, &services_le, sizeof (uint64_t));
  offset += sizeof (uint64_t);

  memcpy (buffer + offset, ip, ipv6_size);
  offset += ipv6_size; 

  uint16_t port_be = htobe16 (port);
  memcpy (buffer + offset, &port_be, sizeof (uint16_t));

  return std::vector<uint8_t> (buffer, buffer + length);
}

net_addr 
net_addr::build_v4 (uint32_t time, uint64_t services, uint32_t ip, uint16_t port)
{
  net_addr addr;
  addr.time = time;
  addr.services = services;
  fill_n (addr.ip, 10, 0);
  fill_n (addr.ip + 10, 2, 0xff);

  uint32_t ip_be = htobe32 (ip);
  uint8_t *bytes = reinterpret_cast<uint8_t*> (&ip_be);
  copy (bytes, bytes + sizeof (uint32_t), addr.ip + 12);
  addr.port = port;

  return addr;
}

net_addr 
net_addr::build_v6 (uint32_t time, uint64_t services, uint8_t ip[ipv6_size], uint16_t port)
{
  net_addr addr;
  addr.time = time;
  addr.services = services;
  fill_n (addr.ip, 12, 0);
  copy (ip, ip + ipv6_size, addr.ip);
  addr.port = port;

  return addr;  
}
