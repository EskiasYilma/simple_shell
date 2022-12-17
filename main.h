#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#define DELIM " \t\n\r"
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

int _putchar(char c);

/* Error Modules */
void swap(char *x, char *y);
char *reverse(char *, int i, int j);
char *_itoa(int value, char *, int base);
void _sprintf(char **, int cmd_cnt, char msg[]);

/* Builtin Modules */
int check_builtins(char *args[], char **, int cmd_cnt);
int e_num_builtins(void);
int e_cd(char **, char **, int n);
int e_help(char **, char **, int n);
int e_exit(char **, char **, int n);

/* Simple Modules */
int _cstrlen(const char *);
void xprint(const char *);
int _strlen(char *);
int _atoi(char *);
char *_memset(char *, char b, unsigned int n);

/* String Modules */
int _strncmp(const char *, const char *, size_t n);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strdup(char *);
char *_strcat(char *, const char *);

/* Read, Tokenize and Loop Modules */
int read_token_loop(char **, int cmd_cnt, char**);
int free_me(char *, char *);

/* Process Creation Modules */
int eval_commands(char *args[], char **, int cmd_cnt);

/* Environment Modules */
void print_env(char **);
char *_getenv(char *, char **);
char *file_exists(char *, char *);

#endif
