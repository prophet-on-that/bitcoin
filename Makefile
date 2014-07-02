libs = -lcrypto
out = peer.bin

header = crypto.h net_addr.h
implementation = peer.cxx crypto.cxx net_addr.cxx
source = $(header) $(implementation)

all:	$(source)
	c++ -o $(out) $(libs) $(implementation)

debug:	$(source)
	c++ -g -o $(out) $(libs) $(implementation)
