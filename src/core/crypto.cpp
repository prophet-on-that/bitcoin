#include "crypto.h"
#include "utils.h"
#include <openssl/sha.h>
#include <cstring>
#include <cstdio>
#include <stdint.h>

using namespace std;

/* 
 * Copied verbatim from stackoverflow:
 * http://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
 * TODO: verify and error checking. Probably want to lose the fixed-length
 * buffer too.
 */
void 
sha256 (char *string, char outputBuffer[65])
{
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init (&sha256);
  SHA256_Update (&sha256, string, strlen(string));
  SHA256_Final (hash, &sha256);
  int i = 0;
  for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
  {
    sprintf (outputBuffer + (i * 2), "%02x", hash[i]);
  }
  outputBuffer[64] = 0;
}

// Post: ret.size () == 32
vector<uint8_t>
sha256 (const vector<uint8_t> &string)
{
  vector<uint8_t> stuff;
  vectorize (14L, stuff);
  return stuff;
}
