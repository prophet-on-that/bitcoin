#include <iostream>
#include <iomanip>
#include "var_int.h"
#include "gtest/gtest.h"

using namespace std;

void
is_equal (vector<uchar> serial, uchar *c, int length)
{
  ASSERT_EQ (serial.size (), length);
  for (int i = 0; i < length; i++)
    EXPECT_EQ (serial[i], c[i]); 
}

TEST(var_int, zero)
{
  const var_int x (0);
  uchar c = 0x0;
  is_equal (x.serialise (), &c, 1);
}

TEST(var_int, one_byte_max)
{
  const var_int x (0xfc);
  uchar c = 0xfc;
  is_equal (x.serialise (), &c, 1);
}

TEST(var_int, two_byte_min)
{
  const var_int x (0xfd);
  uchar c[3];
  c[0] = 0xfd;
  c[1] = 0xfd;
  c[2] = 0x0;
  is_equal (x.serialise (), c, 3);
}

TEST(var_int, hex_ff)
{
  const var_int x (0xff);
  uchar c[3];
  c[0] = 0xfd;
  c[1] = 0xff;
  c[2] = 0x0;
  is_equal (x.serialise (), c, 3);
}

TEST(var_int, hex_1ff)
{
  const var_int x (0x1ff);
  uchar c[3];
  c[0] = 0xfd;
  c[1] = 0xff;
  c[2] = 0x1;
  is_equal (x.serialise (), c, 3);
}

TEST(var_int, two_byte_max)
{
  const var_int x (0xffff);
  uchar c[3];
  c[0] = 0xfd;
  c[1] = 0xff;
  c[2] = 0xff;
  is_equal (x.serialise (), c, 3);
}

TEST(var_int, four_byte_min)
{
  const var_int x (0x10000);
  uchar c[5];
  c[0] = 0xfe;
  c[1] = 0x0;
  c[2] = 0x0;
  c[3] = 0x1;
  c[4] = 0x0;
  is_equal (x.serialise (), c, 5);
}

TEST(var_int, four_byte)
{
  const var_int x (0x12345678);
  uchar c[5];
  c[0] = 0xfe;
  c[1] = 0x78;
  c[2] = 0x56;
  c[3] = 0x34;
  c[4] = 0x12;
  is_equal (x.serialise (), c, 5);
}

TEST(var_int, four_byte_max)
{
  const var_int x (0xffffffff);
  uchar c[5];
  c[0] = 0xfe;
  c[1] = 0xff;
  c[2] = 0xff;
  c[3] = 0xff;
  c[4] = 0xff;
  is_equal (x.serialise (), c, 5);
}

TEST(var_int, eight_byte_min)
{
  const var_int x (0x100000000);
  uchar c[9];
  c[0] = 0xff;
  c[1] = 0x0;
  c[2] = 0x0;
  c[3] = 0x0;
  c[4] = 0x0;
  c[5] = 0x1;
  c[6] = 0x0;
  c[7] = 0x0;
  c[8] = 0x0;
  is_equal (x.serialise (), c, 9);
}

TEST(var_int, eight_byte_max)
{
  const var_int x (0xffffffffffffffff);
  uchar c[9];
  c[0] = 0xff;
  c[1] = 0xff;
  c[2] = 0xff;
  c[3] = 0xff;
  c[4] = 0xff;
  c[5] = 0xff;
  c[6] = 0xff;
  c[7] = 0xff;
  c[8] = 0xff;
  is_equal (x.serialise (), c, 9);
}
