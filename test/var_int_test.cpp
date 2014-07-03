#include <iostream>
#include <iomanip>
#include "../var_int.h"

using namespace std;

int main() {


  /* Test Case 1: 0 */
  {
    var_int x(0);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 1: " << hex << (int) v[0] << endl;
  }

  /* Test Case 2: 0xfc */
  {
    var_int x(0xfc);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 2: " << hex << setfill('0') 
         << setw(2) << (int) v[0] << endl;
  }

  /* Test Case 3: 0xfd */
  {
    var_int x(0xfd);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 3: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << endl;
  }

  /* Test Case 4: 0xff */
  {
    var_int x(0xff);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 4: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << endl;
  }

  /* Test Case 5: 0x1ff */
  {
    var_int x(0x1ff);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 5: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << endl;
  }

  /* Test Case 6: 0xffff */
  {
    var_int x(0xffff);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 6: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << endl;
  }

  /* Test Case 7: 0x10000 */
  {
    var_int x(0x10000);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 7: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << ' ' 
         << setw(2) << (int) v[3] << ' ' 
         << setw(2) << (int) v[4] << endl;
  }

  /* Test Case 8: 0x12345678 */
  {
    var_int x(0x12345678);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 8: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << ' ' 
         << setw(2) << (int) v[3] << ' ' 
         << setw(2) << (int) v[4] << endl;
  }

  /* Test Case 9: 0xffffffff */
  {
    var_int x(0xffffffff);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 9: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << ' ' 
         << setw(2) << (int) v[3] << ' ' 
         << setw(2) << (int) v[4] << endl;
  }

  /* Test Case 10: 0x100000000 */
  {
    var_int x(0x100000000);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 10: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << ' ' 
         << setw(2) << (int) v[3] << ' ' 
         << setw(2) << (int) v[4] << ' ' 
         << setw(2) << (int) v[5] << ' ' 
         << setw(2) << (int) v[6] << ' ' 
         << setw(2) << (int) v[7] << ' ' 
         << setw(2) << (int) v[8] << endl;
  }

  /* Test Case 10: 0xffffffffffffffff */
  {
    var_int x(0xffffffffffffffff);
    std::vector<unsigned char> v = x.serialise();
    cout << "Test 11: " << hex << setw(2) << setfill('0') 
         << setw(2) << (int) v[0] << ' ' 
         << setw(2) << (int) v[1] << ' ' 
         << setw(2) << (int) v[2] << ' ' 
         << setw(2) << (int) v[3] << ' ' 
         << setw(2) << (int) v[4] << ' ' 
         << setw(2) << (int) v[5] << ' ' 
         << setw(2) << (int) v[6] << ' ' 
         << setw(2) << (int) v[7] << ' ' 
         << setw(2) << (int) v[8] << endl;
  }
}
