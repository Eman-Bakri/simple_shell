#include "shellheaders.h"
#include <stdlib.h>

extern char **environ;
void free_env(void);

/**
 * mem_env - Frees the environment memory
 */

void mem_env(void)
{
	int x;

	for (x = 0; environ[x]; x++)
		free(environ[x]);
	free(environ);
}

/**
 * mem_args - Frees the args memory
 * @args: pointer cto arguments.
 * @begin: pointer to the beginning of args.
 */
void mem_args(char **args, char **begin)
{
	size_t y;

	for (y = 0; args[y] || args[y + 1]; y++)
		free(args[y]);

	free(begin);
}

