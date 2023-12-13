#include "shell.h"
/**
 *main - Entry point for the shell program.
 *
 *Return: 0 on successful execution.
 */
int main(void)
{
	char input[128];

	while (true)
	{
		display_prompt();
		read_input(input, sizeof(input));
		exec_command(input);
	}

	return (0);
}
