#include "version.h"
#include "meta.h"
#include "utils.h"
#include <ctime>
#include <cstdlib>

using namespace std;

version::version (const net_addr addr_recv, const net_addr addr_from, 
  const int32_t start_height, const bool relay 
)
  : addr_recv (addr_recv), addr_from (addr_from), user_agent (var_str (USER_AGENT)), start_height (start_height), relay (relay)
{
  _version = VERSION; 
  services = NODE_NETWORK; 
  timestamp = time (NULL);
  nonce = rand ();
}

std::vector<uint8_t> 
version::serialise () const
{
  vector<uint8_t> buffer;

  vectorize (htole32 (_version), buffer);
  vectorize (htole64 (services), buffer);
  vectorize (htole64 (timestamp), buffer);

  vector<uint8_t> temp = addr_recv.serialise ();
  buffer.insert (buffer.begin (), temp.begin (), temp.end ());

  temp = addr_from.serialise ();
  buffer.insert (buffer.begin (), temp.begin (), temp.end ());

  vectorize (htole64 (nonce), buffer);

  temp = user_agent.serialise ();
  buffer.insert (buffer.begin (), temp.begin (), temp.end ());

  vectorize (htole32 (start_height), buffer);
  vectorize (relay, buffer);

  message::build_header (buffer, "version");
  return buffer;
}
