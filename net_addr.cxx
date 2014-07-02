#include "net_addr.h"
#include <sys/endian.h>
#include <cstring>

/*
 * Pre: sizeof serial >= 30
 */
void
net_addr::serialise (char serial[]) const 
{
  // All integers serialised little-endian, except IP and port which use network
  // order (big endian)
  int offset = 0;
  serial[offset] = htole32 (this->time);
  offset += sizeof (uint32_t);
  serial[offset] = htole64 (this->services);
  offset += sizeof (uint64_t);
  strncpy (serial + offset, this->ip, this->ip_size);
  offset += this->ip_size;
  serial[offset] = htobe16 (port);
}
