#ifndef _NET_ADDR_H_
#define _NET_ADDR_H_

#include "serialisable.h"
#include <stdint.h>
#include <vector>

// TODO builders for ipv4 and ipv6
// NOTE Wiki states that net_addr is 26 bytes, but is actually 30 bytes.
// const correctness, constructors etc
struct net_addr : public serialisable {
    static const int ip_size = 16;

    uint32_t time; 
    uint64_t services; 
    // Assume this is in network byte order
    char ip[ip_size];
    uint16_t port;

    std::vector<uint8_t> serialise () const; 
};

#endif
