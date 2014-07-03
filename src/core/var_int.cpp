#include "var_int.h"
#include <string.h>

#include <iostream>

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

var_int::var_int (const var_int &other)
{
  data = other.data;
  length = other.length;
}

var_int::~var_int () {}

std::vector<uchar> var_int::serialise() const {
    std::vector<uchar> buff;

    switch (length) {
        case 3: buff.push_back(0xFD); break;
        case 5: buff.push_back(0xFE); break;
        case 9: buff.push_back(0xFF); break;
    }
        
    for (unsigned int i = 0; i < length; i++) {
        uchar c = (data & (0xFFULL << (8 * i))) >> (8 * i);
        buff.push_back(c);
    }

    return buff;
}

