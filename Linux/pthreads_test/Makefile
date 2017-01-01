COMPILER_OPTIONS = -pthread
LINKER_OPTIONS = -pthread
COMPILE_CPP = g++ $(COMPILER_OPTIONS) -c -o
LINK_TO_EXE = g++ $(LINKER_OPTIONS) -o

.PHONY: clean


test : test.o
	$(LINK_TO_EXE) $@ $^
test.o: test.h

%.o : %.cpp
	$(COMPILE_CPP) $@ $<




clean:
	rm -rf test *.o
