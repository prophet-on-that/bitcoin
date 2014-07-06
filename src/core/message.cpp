#include "message.h"
#include "portable_endian.h"
#include "meta.h"
#include "crypto.h"

#include <string.h>

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void
message::build_header (vector<uint8_t> &payload, const std::string command)
{
    uint32_t length = payload.size ();
    uint32_t magic = MAGIC;

    const int LEN = 12;
    
    uint8_t buffer[LEN] = {'\0'};
    copy (command.c_str (), command.c_str () + command.length (), buffer);

    vector<uint8_t> hash = sha256 (sha256 (payload)); 

    payload.insert (payload.begin (), hash.begin (), hash.begin () + sizeof (uint32_t));

    uint32_t length_le = htole32(length); 
    uint8_t *length_le_bytes = reinterpret_cast<uint8_t *> (&length_le);
    payload.insert (payload.begin (), length_le_bytes, length_le_bytes + sizeof (uint32_t));

    payload.insert (payload.begin (), buffer, buffer + LEN);

    uint32_t magic_le = htole32(magic); 
    uint8_t *magic_le_bytes = reinterpret_cast<uint8_t *> (&magic_le);
    payload.insert (payload.begin (), magic_le_bytes, magic_le_bytes + sizeof (uint32_t));
}

