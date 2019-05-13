#include <stdio.h>

#ifndef PRINT_CS_H_
#include "printcs.h"
#endif

int func() {
    return *(int*)0;
}

int printcs_segmentfault_test() {
    printf("######## test printcs: segment fault test ########\n");
    register_printcs_with_signal(SIGSEGV);
    return func();
}



int main() {
    printcs_segmentfault_test();
    return 0;
}