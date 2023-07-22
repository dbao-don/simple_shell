#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

#define PROMPT "($) "
#define TRUE 1

extern char **environ;

/* Function Prototypes */
int run_shellvoid handle_interrupt(int signal_number);
void handle_interrupt(int signal_number);
#endif
