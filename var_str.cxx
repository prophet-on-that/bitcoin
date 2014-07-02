#include "var_str.h"

using namespace std;

var_str::var_str (const string str)
  : length (var_int::to_var_int (str.length ())) 
{
  this->str = new char[str.length ()]; 
  memcpy (this->str, str.c_str (), str.length ()); /* this avoids copying the null-termiantor */ 
}

var_str::~var_str ()
{
  delete[] str;
}
