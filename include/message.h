#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "serialisable.h"
#include <stdint.h>
#include <vector>

class message 
{
  protected:
    static void build_header (std::vector<uint8_t> &, std::string);
};

#endif
