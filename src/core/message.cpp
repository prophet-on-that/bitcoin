#include "message.h"
#include "portable_endian.h"
#include "meta.h"

#include <string.h>

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

message::message (const std::string command, const uint32_t length, const uint32_t checksum)
  : magic (MAGIC), length (length), checksum (checksum)
{
  assert (command.length () <= NUM_OF_COMMANDS); 

  const char *str = command.c_str ();   

  copy (str, str + command.length (), this->command);

  /* Null pad remainder */
  fill_n (this->command + command.length (), NUM_OF_COMMANDS - command.length (), '\0'); 
}

vector<uint8_t> message::serialise() const {
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

