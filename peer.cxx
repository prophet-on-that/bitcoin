#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>

using namespace std;

/*
 * FORWARD DECLARATIONS
 */

vector<string>
initSeedNodes ();

/*
 * CONSTANTS
 */

// DNS seeds used to bootstrap client connecting to network
const vector<string> seedNodes = initSeedNodes ();
const string port = "8333"; 

/*
 * IMPLEMENTATION
 */

vector<string> 
initSeedNodes ()
{
  vector<string> seedNodes;
  seedNodes.push_back ("seed.bitcoin.sipa.be");
  seedNodes.push_back ("dnsseed.bluematt.me");
  seedNodes.push_back ("dnsseed.bitcoin.dashjr.org");
  seedNodes.push_back ("seed.bitcoinstats.com");
  seedNodes.push_back ("seed.bitnodes.io");
  seedNodes.push_back ("bitseed.xf2.org");
  return seedNodes;
}

/*
 * MAIN STARTS HERE!
 */

int 
main ()
{
  typedef struct addrinfo addrinfo;

  int sockfd, status;
  addrinfo hints;
  addrinfo *servinfo;
  memset (&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  // TODO: error checking, walking servinfo list performing error checking, etc
  if ((status = getaddrinfo (seedNodes[0].c_str (), port.c_str (), &hints, &servinfo)) != 0)
  {
    cerr << "getaddrinfo: " << gai_strerror (status) << endl;
    return 1;
  }

  if ((sockfd = socket (servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) < 0)
  {
    cerr << "socket: error" << endl;
    return 2;
  }

  if (connect (sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0)
  {
    cerr << "connect: error" << endl;
    return 3;
  }

  close (sockfd);
}


