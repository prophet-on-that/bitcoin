#include "net_addr.h"
#include <sys/endian.h>
#include <cstring>

char *
net_addr::serialise () const 
{
  const int SIZE = 30;
  char *serial = new char[SIZE];
  
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
  return serial;
}
