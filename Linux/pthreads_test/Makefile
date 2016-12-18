COMPILE_CPP = g++ -c -o
LINK_TO_EXE = g++ -o

.PHONY: clean


test : test.o
	$(LINK_TO_EXE) $@ $^
test.o: test.h

%.o : %.cpp
	$(COMPILE_CPP) $@ $<




clean:
	rm -rf test *.o
