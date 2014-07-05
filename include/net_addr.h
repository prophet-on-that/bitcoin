#ifndef _NET_ADDR_H_
#define _NET_ADDR_H_

#include "serialisable.h"
#include <stdint.h>
#include <vector>

class net_addr : public serialisable 
{
public:
  static const int ipv6_size = 16;

private:
  uint32_t time; 
  uint64_t services; 
  uint8_t ip[ipv6_size]; // Network byte order (big endian)
  uint16_t port;

  net_addr () {};

public:
  std::vector<uint8_t> serialise () const; 

  static net_addr build_v4 (uint32_t time, uint64_t services, uint32_t ip, uint16_t port);

  // Pre: ip stored in network byte order
  static net_addr build_v6 (uint32_t time, uint64_t services, uint8_t ip[ipv6_size], uint16_t port);

};

#endif
