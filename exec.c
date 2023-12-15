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
<<<<<<< HEAD
	/* Save the current directory */
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		return (EXIT_FAILURE);
	/* Change to the desired directory (optional) */
	if (chdir(".") == -1)
		return (EXIT_FAILURE);
	/* Call execve with environment */
	if (execve(path, argv, environ) == -1)
=======
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
>>>>>>> 50e329c2cf8da5bb0ae32dbb0a49229d5f84af50
	{
		wait(NULL);
	}
<<<<<<< HEAD
	return (EXIT_FAILURE);
}
/**
 * execute_command - execute commands from the user
 * @command: command to be executed
 * @args: argument vector
 *
 * Return: Nothing
 */
void execute_command(char *command, char *args[])
{
	pid_t pid = fork();
	int stat;

	if (pid == -1)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{	/* Child process */
		/* Execute the command in the child process */
		if (execve(command, args, environ) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{  /* Parent process */
		/* Wait for the child process to complete */
		waitpid(pid, &stat, 0);

		/* Optionally, you can print the exit status of the child process */
		if (WIFEXITED(stat))
			print_f("Child process exited with status %d\n", WEXITSTATUS(stat));
		else
			print_f("Child process terminated abnormally\n");
	}
=======
>>>>>>> 50e329c2cf8da5bb0ae32dbb0a49229d5f84af50
}
