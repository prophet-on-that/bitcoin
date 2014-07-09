#ifndef _SERIALISABLE_H
#define _SERIALISABLE_H

#include <vector>
#include <stdint.h>

class serialisable 
{
public:
  virtual std::vector<uint8_t> serialise () const = 0;
  virtual ~serialisable () {};
};

#endif
