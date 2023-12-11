#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int my_execve(const char *path, char *const argv[])
{
	extern char **environ;
	char current_dir[PATH_MAX];

	/* Check if executable exists and has execute permission */
	if (access(path, F_OK | X_OK) == -1)
	{
		perror("Error: Executable not found or permission denied");
		return EXIT_FAILURE;
	}
	/* Save the current directory */
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
		return EXIT_FAILURE;
	/* Change to the desired directory (optional) */
	if (chdir(".") == -1)
		return EXIT_FAILURE;

	/* Call execve with environment */
	if (execve(path, argv, environ) == -1)
	{
		perror("Error");
		chdir(current_dir);
		return EXIT_FAILURE;
	}
	return EXIT_FAILURE;
}
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	/* Use the custom_execve function */
	return my_execve(argv[0], argv);
}
