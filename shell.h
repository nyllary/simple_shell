#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

extern char **environ;

void print(const char *myformat);
void display_prompt(void);
void *read_input(char *input, size_t size);
void exec_command(const char *input);

#endif
