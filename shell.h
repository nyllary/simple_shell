#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void print(const char *myformat);
void display_promt(void);
char *read_input(void);
void exec_command(char *command);


#endif
