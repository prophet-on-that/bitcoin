#ifndef _VAR_STR_H_
#define _VAR_STR_H_

#include "var_int.h"
#include <string>

struct var_str {
    //TODO: Write some kind of accessor..

    const var_int length;
    char* str; /* NOT null-terminated */

    var_str (const std::string);
    ~var_str (); /* Non-virtual, change if used polymorphically */

    char *
    serialise () const;
};

#endif
