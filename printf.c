#include "shell.h"

void print(const char *myformat)
{
	write(STDOUT_FILENO, myformat, strlen(myformat));
}
