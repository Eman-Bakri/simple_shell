#include "shellheaders.h"

/**
 * _comnthandle - handle comments
 * by removing everything after # sign
 *
 * @input: user input or command
 * Return - void
 *
*/
void _comnthandle(char *input)
{
	int m;

	m = 0;
	while (input[m] != '\0')
	{
		if (input[m] == '#')
		{
			input[m] = '\0';
			break;
		}
		m++;
	}
}

