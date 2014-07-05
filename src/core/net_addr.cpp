#include "net_addr.h"
#include <sys/endian.h>
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

  uint32_t time = htole32 (time);
  memcpy (buffer + offset, &time, sizeof (uint32_t));
  offset += sizeof (uint32_t);

  uint64_t services = htole64 (services);
  memcpy (buffer + offset, &services, sizeof (uint64_t));
  offset += sizeof (uint64_t);

  memcpy (buffer + offset, ip, ip_size);
  offset += ip_size; 

  uint16_t port = htobe16 (port);
  memcpy (buffer + offset, &port, sizeof (uint16_t));

  return std::vector<uint8_t> (buffer, buffer + length);
}

net_addr 
net_addr::build_v4 (uint32_t time, uint64_t services, uint32_t ip, uint16_t port)
{
  net_addr addr;
  addr.time = time;
  addr.services = services;
  fill_n (addr.ip, 12, 0);
  uint8_t *bytes = reinterpret_cast<uint8_t*> (&ip);
  copy (bytes, bytes + sizeof (uint32_t), addr.ip + 12);

  return addr;
}

net_addr 
net_addr::build_v6 (uint32_t time, uint64_t services, uint8_t ip[ip_size], uint16_t port)
{
  net_addr addr;
  addr.time = time;
  addr.services = services;
  fill_n (addr.ip, 12, 0);
  copy (ip, ip + ip_size, addr.ip);

  return addr;  
}
