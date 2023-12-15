#include "shell.h"
/**
 *main - Entry point for the shell program.
 *
 *Return: 0 on successful execution.
 */
int main(void)
{
	char input[128];

	if (!isatty(fileno(stdin)))
	{
		fgets(input, sizeof(input), stdin);
		exec_command(input);
		return (0);
	}
	while (true)
	{
		display_prompt();
		read_input(input, sizeof(input));
		exec_command(input);
	}

	return (0);
}
