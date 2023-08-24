#include "shellheaders.h"
#include <stdlib.h>

void free_env(void);

/**
 * mem_env - Free the environment memory
 */

void mem_env(void)
{
	int x;

	for (x = 0; environ[x]; x++)
	{
	/*free memory allocated for the current environment variable*/
		free(environ[x]);
	}
	/* free memory allocated for the array of environment variables*/
	free(environ);
}

