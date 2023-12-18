#include "shell.h"
/**
 *main - Entry point for the shell program.
 *
 *Return: 0 on successful execution.
 */
int main(void)
{
	char input[PATH_MAX];
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	if (!isatty(fileno(stdin)))
	{
		fgets(input, sizeof(input), stdin);
		tokenize(input, argv);
		execute(argv[0], argv);
		return (0);
	}
	while (true)
	{
		display_prompt();
		read_input(input, sizeof(input));
		tokenize(input, argv);
		execute(argv[0], argv);
	}
	return (0);
}
