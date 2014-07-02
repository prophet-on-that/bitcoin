#ifndef _NET_ADDR_H_
#define _NET_ADDR_H_

#include <stdint.h>

// TODO copy constructor, builders for ipv4 and ipv6
struct net_addr {
    static const int ip_size = 16;

    const uint32_t time; 
    const uint64_t services; 
    // Assume this is in network byte order
    const char ip[ip_size];
    const uint16_t port;

    char *serialise () const; 

};

#endif
