#ifndef _VAR_INT_H_
#define _VAR_INT_H_

#include <stdint.h>

struct var_int {
    //TODO: Write some kind of accessor..
    
    const char* data; 

    /* Note function must  most optimise e.g. get passed a value lower
     * than max for uint16_t, store it as a uint16_t!
     */
    static var_int to_var_int (uint64_t); /* rely on implicit casting for other unsigned integer types */

private:
    var_int () {} /* build using only above methods?? */
};

#endif
