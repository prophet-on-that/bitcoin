#include "message_header.h"
#include "gtest/gtest.h"
#include "utils.h"
#include <vector> 

using namespace std;

TEST(message_header, serialise)
{
    const uint32_t magic = 0x1a2b3c4d;
    const uint32_t length = 0x4d3c2b1a;
    const uint32_t checksum = 0x0000ffff; 

    message_header mh; 
    mh.magic = magic; 
    mh.length = length; 
    mh.checksum = checksum; 
   
    //Fill Commands 
    for (int i = 0; i < message_header::NUM_OF_COMMANDS; i++){
        mh.command[i] = i;
    }

    vector<uint8_t> buf = mh.serialise(); 

    for (int i = 0; i < buf.size(); i++) {
        cout << hex << setw(2) << (int) buf[i] << endl;
    }
   
    // Check magic 
    ASSERT_EQ(buf[0], 0x4d); ASSERT_EQ(buf[1], 0x3c);
    ASSERT_EQ(buf[2], 0x2b); ASSERT_EQ(buf[3], 0x1a);

    //Check commands 
    ASSERT_EQ(buf[4], 0x00); ASSERT_EQ(buf[5], 0x01);
    ASSERT_EQ(buf[6], 0x02); ASSERT_EQ(buf[7], 0x03);
    ASSERT_EQ(buf[8], 0x04); ASSERT_EQ(buf[9], 0x05);
    ASSERT_EQ(buf[10], 0x06); ASSERT_EQ(buf[11], 0x07);
    ASSERT_EQ(buf[12], 0x08); ASSERT_EQ(buf[13], 0x09);
    ASSERT_EQ(buf[14], 0x0a); ASSERT_EQ(buf[15], 0x0b);

    //Check length
    ASSERT_EQ(buf[16], 0x1a); ASSERT_EQ(buf[17], 0x2b);
    ASSERT_EQ(buf[18], 0x3c); ASSERT_EQ(buf[19], 0x4d);

    //Check checksum
    ASSERT_EQ(buf[20],  0xff); ASSERT_EQ(buf[21],  0xff);
    ASSERT_EQ(buf[22],  0x00); ASSERT_EQ(buf[23],  0x00);
}
