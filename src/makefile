.PHONY: clean

default: printcs-test
# Define the tools we are going to use
CC= g++
LD = g++

LIBS = -lm -lc -lpthread
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -I.

printcs-test: printcs_test.o printcs.o
	$(LD) $(CFLAGS) -o $@ $^ $(LIBS)
	./printcs-test

printcs_test.o: printcs_test.c
	$(CC) $(CFLAGS) -c -o $@ $< 

printcs.o: printcs.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm  printcs-test *.o