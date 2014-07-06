#ifndef _MESSAGE_HEADER_H_
#define _MESSAGE_HEADER_H_

#include "serialisable.h"
#include <stdint.h>

struct message_header : public serialisable {
    static const int NUM_OF_COMMANDS = 12; 

    uint32_t magic;
    int8_t command[NUM_OF_COMMANDS];
    uint32_t length;
    uint32_t checksum; 

    std::vector<uint8_t> serialise () const;
};

#endif
