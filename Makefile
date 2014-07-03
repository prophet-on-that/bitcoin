# NOTE this is not GNU Make, but FreeBSD Make. Not compatible!

INCLUDE_DIR 	= $(.CURDIR)/include
SRC_DIR     	= $(.CURDIR)/src
OBJ_DIR	    	= $(.CURDIR)/obj
LIB_DIR	    	= $(.CURDIR)/lib
BIN_DIR		= $(.CURDIR)/bin

#########################
# Build shared library #
#########################

all:	core peer

CORE_SRC 	= $(SRC_DIR)/core/*.cpp
LIB_SRC  	= $(INCLUDE_DIR)/*.h

LIB_OUT		= $(LIB_DIR)/libbitcoin.so
LIB_CFLAGS 	= -Wall -shared -fPIC -o $(LIB_OUT) -lcrypto -I$(INCLUDE_DIR)

core: 	$(CORE_SRC) $(LIB_SRC)
	c++ $(LIB_CFLAGS) $(CORE_SRC)

##############
# Build peer #
##############

PEER_SRC 	= $(SRC_DIR)/peer/*.cpp

PEER_OUT	= $(BIN_DIR)/peer.bin
PEER_CFLAGS	= -o $(PEER_OUT)

peer:	$(PEER_SRC)
	c++ $(PEER_CFLAGS) $(PEER_SRC)
