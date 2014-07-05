#include "var_str.h"

using namespace std;

vector<uint8_t> 
var_str::serialise() const
{
  vector<uint8_t> ret = var_int (str.length ()).serialise ();
  const char *temp = str.c_str ();

  // No null-terminator
  ret.insert (ret.end (), temp, temp + str.length ());

  return ret;
}
