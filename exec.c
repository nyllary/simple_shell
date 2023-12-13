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
 * main - entry point
 *
 * Return: Always 0(Success)
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	/* Use the custom_execve function */
	return (my_execve(argv[0], argv));
}
