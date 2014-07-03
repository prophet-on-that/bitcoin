#include "net_addr.h"
#include <sys/endian.h>
#include <cstring>
#include <vector>

std::vector<uchar>
net_addr::serialise () const 
{
  // All integers serialised little-endian, except IP and port which use network
  // order (big endian)
  int length = 30;

  // Build serialised representation first in uchar buffer, then return as
  // vector
  uchar buffer[length];
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

  return std::vector<uchar> (buffer, buffer + length);
}
