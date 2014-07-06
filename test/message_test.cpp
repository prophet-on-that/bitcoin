#include "message.h"
#include "gtest/gtest.h"
#include "utils.h"
#include <vector> 

using namespace std;

class message_test : public message 
{
public: 
    static void call_build_header (std::vector<uint8_t> &v, std::string s){
      build_header(v, s);
    }
}; 

TEST(message, empty)
{
  vector<uint8_t> empty_vector; 
  string s = "Empty";

  message_test::call_build_header(empty_vector, s);

  uint8_t buf[] = { 0x0b , 0x11 , 0x09 , 0x07 , 0x45 , 0x6d , 0x70 , 0x74 , 0x79
      , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
        0x00 , 0x0e , 0x00, 0x00, 0x00};

  is_equal (empty_vector, buf, 24);
}

