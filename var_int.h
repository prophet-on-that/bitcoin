#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>
#include <cstdlib>
#include <vector>

class var_int {
  //TODO: Write some kind of accessor..
  //TODO: USE vector<char>?
  //TODO: Store as uint64_t, convert to weird format on serialisation 
private:
  uint64_t data; 
  size_t length;

  /* Note function must  most optimise e.g. get passed a value lower
   * than max for uint16_t, store it as a uint16_t!
   */
public:
  var_int (const uint64_t);
  var_int (const var_int &other);

  std::vector<unsigned char> serialise();

  ~var_int ();
};

#endif
