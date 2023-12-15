#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_TOKENS 100

extern char **environ;
char *str_dup(const char *str);
int _putchar(char c);
void print_f(const char *format, ...);

#endif
