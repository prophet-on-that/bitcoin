#include <iostream>
#include "../var_int.h"

using namespace std;

int main() {


  /* Test Case 1: 0 */
  {
    var_int x(0);
    //cout << x.serialized....  
  }

  /* Test Case 2: 0xfc */
  {
    var_int x(0xfc);
    //cout << x.serialized....  
  }

  /* Test Case 3: 0xfd */
  {
    var_int x(0xfd);
    //cout << x.serialized....  
  }

  /* Test Case 4: 0xffff */
  {
    var_int x(0xffff);
    //cout << x.serialized....  
  }

  /* Test Case 5: 0x10000 */
  {
    var_int x(0x10000);
    //cout << x.serialized....  
  }

  /* Test Case 6: 0xffffffff */
  {
    var_int x(0xffffffff);
    //cout << x.serialized....  
  }

  /* Test Case 7: 0x100000000 */
  {
    var_int x(0x100000000);
    //cout << x.serialized....  
  }


  cout << "lololol" << endl;

}
