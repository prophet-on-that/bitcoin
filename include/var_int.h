#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>
#include <cstdlib>
#include <vector>
#include "serialisable.h"

class var_int : public serialisable {
private:
  uint64_t data; 
  size_t length;

  /* Note function must  most optimise e.g. get passed a value lower
   * than max for uint16_t, store it as a uint16_t!
   */
public:
  var_int (const uint64_t);

  uint64_t get () const { return data; }
  std::vector<uint8_t> serialise() const;

};

#endif
