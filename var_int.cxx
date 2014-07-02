#include "var_int.h"

var_int::var_int (const uint64_t n)
{
  if (n < 0xFD)
  {
    data = (char*) malloc(1);
    data[0] = n & 0xFF;
  } else if (n < 0xFFFF)
  {
    // allocate 3 bytes
    data = (char*) malloc(3);

    data[0] = 0xFE;
    data[1] = n & 0xFF;
    data[2] = (n  >> 8) & 0xFF;

  } else if (n < 0xFFFFFFFF)
  {
    // allocate 5 bytes
    data = (char*) malloc(5);

    data[0] = 0xFE;
    
    for (int i = 0; i < 4; i++)
    {
      data[i + 1] = (n >> (i * 8)) & 0xFF;
    }
  } else
  {
    // allocate 9 bytes
    data = (char*) malloc(9);

    data[0] = 0xFF;

    for (int i = 0; i < 8; i++)
    {
      data[i + 1] = (n >> (i * 8)) & 0xFF;
    }
  }
}
