#include "shell.h"
/**
 *read_input - reads the input from user into a pre-allocated buffer
 *
 *@input: a pre-allocated buffer to store the input
 *@size: the size of buffer
 *
 *Return: Nothing
 */
void *read_input(char *input, size_t size)
{

	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print("End of input\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print("Error while reading your input.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		input[strcspn(input, "\n")] = '\0';
		return (input);
	}
}
