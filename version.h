#ifndef _VERSION_H_
#define _VERSION_H_

#include <stdint.h>
#include "message_header.h"
#include "net_addr.h"
#include "var_str.h"

struct Version { 
    MessageHeader messageHeader; 

    int32_t version; 
    uint64_t services;
    int64_t timestamp;

    net_addr addr_recv;
    net_addr addr_from; 
    uint64_t nonce;
    var_str user_agent;
    int32_t start_height;
    bool relay; // XXX: Should this be a char? 
};

#endif
