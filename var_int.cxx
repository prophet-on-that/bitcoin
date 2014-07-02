#include "var_int.h"
#include <string.h>

var_int::var_int (const uint64_t n)
{
  if (n < 0xFD)
  {
    data = new char[1];
    data[0] = n & 0xFF;
    length = 1;
  } 
  else if (n < 0xFFFF)
  {
    data = new char[3];
    length = 3;
    data[0] = 0xFE;
    uint16_t value = (uint16_t)(n & 0xFFFF);
    memcpy(&data[1],&value,2);
  } 
  else if (n < 0xFFFFFFFF)
  {
    data = new char[5];
    length = 5;
    data[0] = 0xFE;
    uint32_t value = (uint32_t)(n & 0xFFFFFFFF);
    memcpy(&data[1],&value,4);
  } 
  else
  {
    data = new char[9];
    length = 9;
    data[0] = 0xFF;
    memcpy(&data[1],&n,8);
  }
}

var_int::var_int (const var_int &other)
{
  data = new char[other.length];
  memcpy (this->data, other.data, other.length); 
}

var_int::~var_int () 
{
  delete[] data;
}

