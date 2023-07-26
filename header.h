#ifndef HEADER_H
#define HEADER_H
/* Function prototypes */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define PROMPT "$ "
#define ERR_MSG ": not found\n"
#define ERR_PATH ": No such file or directory\n"
#define NA_NO ": sh: 1: exit: Illegal number: "
char **str_tokens(char *str);
int create_fork(char *shell_name, char **tokens, char **env, int is_terminal);
int check_exit(char **tokens, char *shell_name, char **env);
char *get_path(char **env);
char *split_path(char *file_token, char *path);
int _strlen(char *s);
int _strcmp(char *a, char *b);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
#endif
