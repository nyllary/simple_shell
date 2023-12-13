#include <stdio.h>
#include <stdarg.h>
/**
 * print_f - prints to standard out
 *  @format: data type of text to be printed out
 *
 *  Return:
 */

void print_f(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vprintf(format, args);

	va_end(args);
}
