#include "shellheaders.h"
#include <string.h>
#include <malloc.h>
/**
 * _mystrsplit - seperate string on a specific seperator
 * into multiple tokens
 * @str: string
 * @sprt: seperator we divide based on
 * Return: a pointer to a string having the next token
 * otherwise Null.
*/
char *_mystrsplit(char *str, const char *sprt)
{
	/* static char var tracing str index in every call */
	static char *m;

	/*the beginning passing the str to divide based on */
	if (str != NULL)
		m = str;
	else
		str = m;

	/*check index*/
	if (*m == '\0')
		return (NULL);

	while (*m != '\0')
	{
		int in;
		/*loop over each seperator and search for a match*/
		for (in = 0; sprt[in] != '\0'; in++)
		{
			if (*m == sprt[in])
			{
				/* when two seperators follow each other */
				if (m == str)
				{
					m++;
					str++;
				}
				else
				{
					*m = '\0';
					break;
				}
			}
		}
		/*return the token*/
		if (*m == '\0')
		{
			m++;
			return (str);
		}
		m++;
	}
	return (str);
}

