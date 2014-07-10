#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <vector>
#include <stdint.h>

// POST: ret.size () == 32
std::vector<uint8_t>
sha256 (const std::vector<uint8_t> &message);

#endif
