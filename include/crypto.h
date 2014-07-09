#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <vector>
#include <stdint.h>

void
sha256 (char *string, char outputBuffer[65]);

// Post: ret.size () == 32
std::vector<uint8_t>
sha256 (const std::vector<uint8_t> &string);

#endif
