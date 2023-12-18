#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <limits.h>

#define MAX_TOKENS 100

extern char **environ;

void tokenize(char *input, char *tokens[]);
char *str_dup(const char *str);
int _putchar(char c);
void print(const char *myformat, ...);
void display_prompt(void);
void *read_input(char *input, size_t size);
void execute(char *command, char *argv[]);

#endif
