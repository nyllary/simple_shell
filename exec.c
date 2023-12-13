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
		execlp(input, input, (char *) NULL);
		perror("Execution error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
