#ifndef _META_H
#define _META_H

/*
 * Protocol constants
 */

#ifdef LIVE 
  #define MAGIC 0xD9B4BEF9 /* main */
#else 
  #define MAGIC 0x0709110B /* testnet3 */
#endif 

#define VERSION 70001 /* the protocol specification */
#define NODE_NETWORK 1 /* a service */

#endif 
