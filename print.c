#include "shell.h"
/**
 * print - prints to standard out
 *  @myformat: data type of text to be printed out
 *
 *  Return: void (no return value)
 */
void print(const char *myformat)
{
	write(STDOUT_FILENO, myformat, strlen(myformat));
}
