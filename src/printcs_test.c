#include <stdio.h>

#ifndef PRINT_CS_H_
#include "printcs.h"
#endif

void printcs_test() {
    printf("######## test printcs ########\n");
    printcs();
}

void register_printcs_with_signal_test(unsigned long int sig) {
    printf("######## test printcs ########\n");
    register_printcs_with_signal(sig);
    kill(getpid(), SIGINT);
}

int main() {
    printcs_test();
    register_printcs_with_signal_test(SIGINT);
}