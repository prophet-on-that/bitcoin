#ifndef _MESSAGE_HEADER_H_
#define _MESSAGE_HEADER_H_

#include <stdint.h>

struct MessageHeader {
    uint32_t magic;
    char command[12];
    uint32_t length;
    uint32_t checksum; 
};

#endif
