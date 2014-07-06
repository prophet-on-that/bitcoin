#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "serialisable.h"
#include <stdint.h>

class message : public serialisable {

public:
    std::vector<uint8_t> serialise () const;

protected:
    message (const std::string command, const uint32_t length, const uint32_t checksum);

private:
    static const int NUM_OF_COMMANDS = 12; 

    const uint32_t magic;
    int8_t command[NUM_OF_COMMANDS]; /* Non const because non-trivial to assign to */
    const uint32_t length;
    const uint32_t checksum; 
};

#endif
