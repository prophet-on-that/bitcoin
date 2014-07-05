#include "gtest/gtest.h"
#include "var_str.h"
#include "utils.h"
#include <algorithm>

using namespace std;

TEST (var_str, empty)
{
  const var_str x (""); 
  uint8_t s = 0x0;
  is_equal (x.serialise (), &s, 1);
}

TEST (var_str, singleton)
{
  const var_str x ("x");
  uint8_t s[2];
  s[0] = 0x1;
  s[1] = 'x';
  is_equal (x.serialise (), s, 2);
}

TEST (var_str, length_253)
{
  const var_str x (string (253, 'x'));
  const int length = 256;
  uint8_t s[length];
  s[0] = 0xfd;
  s[1] = 0xfd;
  s[2] = 0x0;
  fill_n (s + 3, 253, 'x');
  is_equal (x.serialise (), s, length);
}
