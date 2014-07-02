#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>

struct var_int {
    //TODO: Write some kind of accessor..
    
    // needs to be stored little-endian
    const char* data; 

    static var_int to_var_int (uint16_t);
    static var_int to_var_int (uint32_t);
    static var_int to_var_int (uint64_t);

private:
    var_int () {} /* build using only above methods?? */
};

#endif
