#include "message_header.h"
#include "portable_endian.h"

#include <string.h>

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<uint8_t> message_header::serialise() const {
    int len = 24;
    
    uint8_t buffer[len];
    int offset = 0;

    uint32_t magic_le = htole32(magic); 
    memcpy (buffer + offset, &magic_le, sizeof (uint32_t)); 
    offset += sizeof(uint32_t);

    memcpy (buffer + offset, command, NUM_OF_COMMANDS);
    offset += NUM_OF_COMMANDS;

    uint32_t length_le = htole32(length); 
    memcpy (buffer + offset, &length_le, sizeof (uint32_t)); 
    offset += sizeof(uint32_t);

    uint32_t checksum_le = htole32(checksum); 
    memcpy (buffer + offset, &checksum_le, sizeof (uint32_t)); 
    offset += sizeof(uint32_t);

    return std::vector<uint8_t>(buffer, buffer + len);
}

