#include "shell.h"

/**
 * tokenize - breaks user input into 0s and 1s
 * @input: user input
 * @tokens: array cotaining tokens
 *
 * Returns: nothing
 */
void tokenize(char *input, char *tokens[])
{
	int i = 0;
	char *token = strtok(input, " \t\n");

	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
}
