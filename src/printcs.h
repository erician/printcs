#ifndef PRINT_CS_H_
#define PRINT_CS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <syscall.h>

#define BT_BUF_SIZE 1024    // should be larger enough to hold the call stack info

void printcs(void);
void register_printcs_with_signal(unsigned long int signo);

#ifdef __cplusplus
}
#endif

#endif