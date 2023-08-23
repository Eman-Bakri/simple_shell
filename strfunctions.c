#include "shellheaders.h"

/**
 * _strlen - take a string
 * and return its length
 *
 * @str: string argent
 * Return - the length of str
 *
*/
unsigned int _strlen(const char *str)
{
	unsigned int lengthcount = 0;
	while(*str !='\0')
	{
		lengthcount++;
		str++;
	}
	return (lengthcount);
}
/**
 * _strcat - concat two strings
 * src and dest
 *
 * @deststr: dest string
 * @srcstr: src string
 * Return - the dest str
 *
*/
char *_strcat(char *deststr, const char *srcstr)
{
	/*A pointer to the end of the dest string*/
	char *pointer = deststr + _strlen(deststr);

	/* attach chars one by one from the src to dest string*/
	while (*srcstr != '\0')
	{
		*pointer++ = *srcstr++;
	}
	/* Terminate dest string*/
	*pointer = '\0';
	return (deststr);
}
/**
 * _strcpy - copy src string
 * into dest str
 *
 * @deststr: dest string
 * @srcstr: src string
 * Return - the pointer dest
 * 
*/
char *_strcpy(char *deststr, const char *srcstr)
{
	char *pointer;
	/*check when no memory is allocated to dest*/
	if (deststr == NULL)
	{
		return (NULL);
	}
	/*A pointer to the beginning of the dest string*/
	pointer = deststr;
	/* copy src into dest pointed array */
	while (*srcstr != '\0')
	{
		*deststr = *srcstr;
		deststr++;
		srcstr++;
	}
	/* Terminate*/
	*deststr = '\0';
	return (pointer);
}
/**
 * _strcmp - compare two str
 * and return an int
 *
 * @str1: first str to compare
 * @str2: second str
 * Return - int value define the result
*/
int _strcmp(const char *str1, const char *str2)
{
	while (*str1)
	{
		/*if str chars are different, or it is str2 last char*/
		if (*str1 != *str2)
		{
			break;
		}
		/*next chars pair */
		str1++;
		str2++;
	}
	/* convert and return ASCII diff */
	return (*(const unsigned char*)str1 - *(const unsigned char*)str2);
}

