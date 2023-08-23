#include "shellheaders.h"

/**
 * main - main shell program
 * @ac: argument count
 * @av: argument value
 * @env: environment variable
 *
 * Return: 0
*/
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt_display(av, env);
	return (0);
}

