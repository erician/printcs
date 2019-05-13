#ifndef PRINT_CS_H_
#include "printcs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void printcs(void) {
    int i, nptrs;
    void *buffer[BT_BUF_SIZE];
    char **strings;

    nptrs = backtrace(buffer, BT_BUF_SIZE);
    strings = backtrace_symbols(buffer, nptrs);
    if (strings == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    char *exefile_name = getenv("_");
    char sys_command[256];
    printf("the call stack is: \n");
    for (i = 0; i < nptrs; i++) {
        printf("[call stack] #%d pid: %ld\n", i, pthread_self());
        sprintf(sys_command, "addr2line %p -e %s -f -s -p ", \
        buffer[i], exefile_name);
        system(sys_command);
        printf("\n");
    }
    free(strings);
}

void __printcs(int signo) {
    printcs();
    exit(signo);
}

void register_printcs_with_signal(unsigned long int signo) {
    signal(signo, __printcs);
}

#ifdef __cplusplus
}
#endif