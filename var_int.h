#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>

class var_int {
  //TODO: Write some kind of accessor..
private:
  const char* data; 

  /* Note function must  most optimise e.g. get passed a value lower
   * than max for uint16_t, store it as a uint16_t!
   */
public:
  var_int (const uint64_t);
};

#endif
