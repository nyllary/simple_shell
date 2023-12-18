#include "shell.h"
/**
 * print - prints to standard out
 *  @myformat: data type of text to be printed out
 *
 *  Return: void (no return value)
 */
void print(const char *myformat, ...)
{
	va_list args;

	va_start(args, myformat);
	vprintf(myformat, args);

	va_end(args);
}
