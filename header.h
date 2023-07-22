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
#define ERR_MSG ": not found\n"
#define ERR_PATH "Fail to find PATH\n"

extern char **environ;

/* Function Prototypes */
int run_shell(char *argv[], char *envp[]);
void handle_interrupt(int signal_number);
void free_buf(char *s, int len, char *buffer, char *state);
int exec_child(char *cmnd, char *arg[], char *buffer, char *av, char *env[]);
int check_exit(char *s);
int to_int(char *str);
char *find_path(char **env, char *variable);
int str_compare(char *str1, char *str2);
char *construct_path(char *command, char *env);
char *str_concat(char *dest, char *src);
int str_length(char *s);

#endif
