.PHONY: clean printcs-test printcs-segmentfault-test

default: printcs-test
# Define the tools we are going to use
CC= g++
LD = g++

LIBS = -lm -lc -lpthread
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare -I.


printcs-segmentfault-test: printcs_segmentfault_test.o printcs.o
	$(LD) $(CFLAGS) -o $@ $^ $(LIBS)

printcs-test: printcs_test.o printcs.o
	$(LD) $(CFLAGS) -o $@ $^ $(LIBS)

printcs_segmentfault_test.o: printcs_segmentfault_test.cc
	$(CC) $(CFLAGS) -c -o $@ $<
printcs_test.o: printcs_test.c
	$(CC) $(CFLAGS) -c -o $@ $< 
printcs.o: printcs.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f printcs-test printcs-segmentfault-test *.o