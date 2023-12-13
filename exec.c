#include "shell.h"
/**
 *exec_command - this funtions executes all user inputs
 *
 *@input: The command to be executed
 *Return: nothing
 */
void exec_command(const char *input)
{
	pid_t baby_pid = fork();

	if (baby_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (baby_pid == 0)
	{
		char **args = malloc(2 * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = (char *)input;
		args[1] = NULL;

		if (execve(input, args, environ) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}

		free(args);
	}
	else
	{
		wait(NULL);
	}
}
