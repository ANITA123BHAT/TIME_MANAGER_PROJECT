#This makefile shall create the test_application binary
#CC=g++
#OPT=-O0
#CFLAGS=-Wall -Wextra -g $(OPT)
#LIBDIR=./

#BINARY=test
#all:$(BINARY)

#SOURCECODE=$(foreach SRC,$(LIBDIR),$(wildcard $(SRC)/*.cpp));
#OBJFILE=$(patsubst %.cpp,%.o,$(SOURCECODE))

#%.o:%.cpp
#	$(CC) $(CFLAGS) -c -o $@ $<



#clean:
#	rm -rf $(BINARY) $(OBJECTS)


all:run

INCLUDE=../lib/include/
#INCLUDES=../lib/src

create_executable:
	g++ -I$(INCLUDE) -o test sample_application.cpp -ltime_lib -L ../lib -Wl,-R../lib

run:create_executable
	./test
