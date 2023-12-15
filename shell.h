#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
<<<<<<< HEAD
#include <stdarg.h>
#include <stdlib.h>

#define MAX_TOKENS 100

extern char **environ;
char *str_dup(const char *str);
int _putchar(char c);
void print_f(const char *format, ...);
=======

extern char **environ;

void print(const char *myformat);
void display_prompt(void);
void *read_input(char *input, size_t size);
void exec_command(const char *input);
>>>>>>> 50e329c2cf8da5bb0ae32dbb0a49229d5f84af50

#endif
