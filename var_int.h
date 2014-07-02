#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>
#include <cstdlib>

class var_int {
  //TODO: Write some kind of accessor..
private:
  char* data; 
  size_t length;

  /* Note function must  most optimise e.g. get passed a value lower
   * than max for uint16_t, store it as a uint16_t!
   */
public:
  var_int (const uint64_t);
  var_int (const var_int &other);
  ~var_int ();
};

#endif
