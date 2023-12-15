#include "shell.h"
/**
 * my_execve - executes command
 * @path: directory of the executable files
 * @argv: argument vector
 *
 * Return: The number of executable commands found
 */

int my_execve(const char *path, char *const argv[])
{
	char current_dir[PATH_MAX];

	/* Check if executable exists and has execute permission */
	if (access(path, F_OK | X_OK) == -1)
	{
		perror("Error: Executable not found or permission denied");
		return (EXIT_FAILURE);
	}
	/* Save the current directory */
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		return (EXIT_FAILURE);
	/* Change to the desired directory (optional) */
	if (chdir(".") == -1)
		return (EXIT_FAILURE);
	/* Call execve with environment */
	if (execve(path, argv, environ) == -1)
	{
		perror("Error");
		chdir(current_dir);
		return (EXIT_FAILURE);
	}
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
}
