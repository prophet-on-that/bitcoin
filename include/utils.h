#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include <stdint.h>

template<typename t>
std::vector<uint8_t> 
vectorize (t data) {
    uint8_t *bytes = reinterpret_cast<uint8_t *> (&data);
    return std::vector<uint8_t>(bytes, bytes + sizeof(t));
}

template<typename t>
void
vectorize (t data, std::vector<uint8_t> &buffer) {
    std::vector<uint8_t> bytes = vectorize (data);
    buffer.insert (buffer.end (), bytes.begin (), bytes.end ());
}
      
#endif
