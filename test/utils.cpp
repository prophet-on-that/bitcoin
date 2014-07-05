#include "utils.h"
#include "gtest/gtest.h"

using namespace std;

void
is_equal (const vector<uint8_t> serial, const uint8_t *c, const int length)
{
  ASSERT_EQ (length, serial.size ());
  for (int i = 0; i < length; i++)
    EXPECT_EQ (c[i], serial[i]); 
}

