#include "crypto.h"
#include <openssl/evp.h>
#include <cstring>
#include <cstdio>
#include <stdint.h>

using namespace std;

// Ret: non-zero on failure
// Post: ret.size () == 32
// TODO: exceptions?
vector<uint8_t>
sha256 (const vector<uint8_t> &message)
{
  int length = message.size ();
  uint8_t buffer[length];
  for (int i = 0; i < length; i++)
    buffer[i] = message[i];

  unsigned char md_value[EVP_MAX_MD_SIZE];
  unsigned int md_len;
  EVP_MD_CTX *mdctx = EVP_MD_CTX_create ();
  const EVP_MD *md = EVP_sha256 ();
  if (!md)
  {
    return vector<uint8_t> ();
  }

  EVP_DigestInit_ex (mdctx, md, NULL);
  EVP_DigestUpdate (mdctx, buffer, length);
  EVP_DigestFinal_ex (mdctx, md_value, &md_len);
  EVP_MD_CTX_destroy (mdctx);

  vector<uint8_t> out;
  for (unsigned int i = 0; i < md_len; i++)
    out.push_back (md_value[i]);

  return out;
}
