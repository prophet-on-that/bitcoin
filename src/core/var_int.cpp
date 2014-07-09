#include "var_int.h"
#include <string.h>

#include <iostream>
#include <algorithm>

using namespace std;

var_int::var_int (const uint64_t n)
{
    data = n;

    if (data < 0xFD) { 
        length = 1; 
    } else if (data <= 0xFFFF) { 
        length = 3; 
    } else if (data <= 0xFFFFFFFF) { 
        length = 5; 
    } else { 
        length = 9; 
    }
}

vector<uint8_t> var_int::serialise() const {
    vector<uint8_t> buff;

    switch (length) {
        case 3: buff.push_back(0xFD); break;
        case 5: buff.push_back(0xFE); break;
        case 9: buff.push_back(0xFF); break;
    }

    unsigned int size = max (1UL, length - 1);
    for (unsigned int i = 0; i < size; i++) {
        uint8_t c = (data & (0xFFULL << (8 * i))) >> (8 * i);
        buff.push_back(c);
    }

    return buff;
}

