#ifndef _VERSION_H
#define _VERSION_H

#include "message.h"
#include "net_addr.h"
#include "var_str.h"
#include <stdint.h>

class version : public message, public serialisable 
{
  int32_t _version; 
  uint64_t services;
  int64_t timestamp;

  net_addr addr_recv;
  net_addr addr_from; 
  uint64_t nonce;
  var_str user_agent;
  int32_t start_height;
  bool relay; 

public:  
  /*
   * Final argument relay requires you to specify in order to use, as true gives
   * the pre-v70001 behaviour
   */
  version (const net_addr addr_recv, const net_addr addr_from, 
    const int32_t start_height, const bool relay = true
  );

  std::vector<uint8_t> serialise () const;
};

#endif
