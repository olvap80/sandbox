COMPILER_OPTIONS = -std=c++11 -Wall -pedantic -pthread
LINKER_OPTIONS = -pthread
COMPILE_CPP = g++ $(COMPILER_OPTIONS) -c -o
LINK_TO_EXE = g++ $(LINKER_OPTIONS) -o

.PHONY: clean

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

test : $(OBJ)
	$(LINK_TO_EXE) $@ $^
test.o: test.h

%.o : %.cpp
	$(COMPILE_CPP) $@ $<




clean:
	rm -rf test *.o
