#ifndef _SERIALISABLE_H
#define _SERIALISABLE_H

#include <vector>

class serialisable 
{
  virtual vector<char> serialise () const = 0;
};

#endif
