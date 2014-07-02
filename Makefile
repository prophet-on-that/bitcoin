libs = -lcrypto
out = peer.bin

header = crypto.h
implementation = peer.cxx crypto.cxx 
source = $(header) $(implementation)

all:	$(source)
	c++ -o $(out) $(libs) $(implementation)

debug:	$(source)
	c++ -g -o $(out) $(libs) $(implementation)
