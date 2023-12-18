#include "shell.h"

/**
 * execute - runs command input
 * @command: received command/input
 * @args: an array of arguments to be passed to the command
 *
 * Return: Nothing
 */

void execute(char *command, char *args[])
{
	pid_t pid = fork();
	int stat;

	if (pid == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(command, args, environ) == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &stat, 0) == -1)
		{
			perror("Error: waitpid failed");
			exit(EXIT_FAILURE);
		}
	}
}
