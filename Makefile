# NOTE this is not GNU Make, but FreeBSD Make. Not compatible!

INCLUDE_DIR 	= $(.CURDIR)/include
SRC_DIR     	= $(.CURDIR)/src
OBJ_DIR	    	= $(.CURDIR)/obj
LIB_DIR	    	= $(.CURDIR)/lib
BIN_DIR		= $(.CURDIR)/bin
TEST_DIR	= $(.CURDIR)/test
TOOLS_DIR	= $(.CURDIR)/tools

#########################
# Build shared library #
#########################

all:	core peer build_test run_test

CORE_SRC 	= $(SRC_DIR)/core/*.cpp
LIB_SRC  	= $(INCLUDE_DIR)/*.h

LIB_OUT		= $(LIB_DIR)/libbitcoin.so
LIB_CFLAGS 	= -g -Wall -shared -fPIC -o $(LIB_OUT) -lcrypto -I$(INCLUDE_DIR)

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

###############
# Build tests #
###############

TEST_HEADER	= $(TEST_DIR)/*.h
TEST_SRC 	= $(TEST_DIR)/*.cpp
TEST_OUT 	= $(BIN_DIR)/test.bin

build_test:	$(TEST_SRC) $(TEST_HEADER)
	c++ -g -pthread -I$(TOOLS_DIR)/gtest/include -I$(INCLUDE_DIR) $(TEST_SRC) -L$(TOOLS_DIR)/gtest -L$(LIB_DIR) -lgtest -lbitcoin -Wl,-R$(LIB_DIR) -o $(TEST_OUT) 

#############
# Run tests #
#############

run_test:	
	$(TEST_OUT)

test:	build_test run_test
