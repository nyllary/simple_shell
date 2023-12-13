#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include <string.h>
#include <limits.h>
#include <sys/wait.h>
#include <stdarg.h>

void print(const char *myformat);
void display_promt(void);
char *read_input(void);
void exec_command(char *command);
extern char **environ;
int _putchar(char c);
void print(const char *myformat);
>>>>>>> d7889f239203a29d443a3d731bb54fa778e52f87

#endif
