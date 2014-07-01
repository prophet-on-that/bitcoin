#ifndef _NET_ADDR_H_
#define _NET_ADDR_H_

struct net_addr {

    uint32_t time; 
    uint64_t services; 
    char IP[16];
    uint16_t port;

};

#endif
