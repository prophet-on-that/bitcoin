libs = 
out = test.bin

header = ../var_int.h 
implementation = ../var_int.cxx var_int_test.cpp
source = $(header) $(implementation)

all:	$(source)
	c++ -o $(out) $(libs) $(implementation)

debug:	$(source)
	c++ -g -o $(out) $(libs) $(implementation)
