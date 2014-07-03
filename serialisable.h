#ifndef _SERIALISABLE_H
#define _SERIALISABLE_H

#include <vector>
#include "typedefs.h"

class serialisable 
{
public:
  virtual std::vector<uchar> serialise () const = 0;
};

#endif
