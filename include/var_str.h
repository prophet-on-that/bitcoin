#ifndef _VAR_STR_H_
#define _VAR_STR_H_

#include "var_int.h"
#include <string>

struct var_str : public serialisable {
    const std::string str;

    var_str (const std::string str) : str (str) {}
    std::vector<uint8_t> serialise() const;
};

#endif
