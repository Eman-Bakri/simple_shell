#include "shellheaders.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * own_cd - Changes the current directory.
 *
 * @cd_arg: The cd argument
 *
 * Return: Always 0 (Success)
 */

int own_cd(char *cd_arg)
{
	__attribute__((unused)) char *curr_dir = getcwd(NULL, 0);
	char *home_dir = getenv("HOME");
	char *oldpath = getenv("OLDPWD");

	/*if argument is NULL or ~ return to home directory*/
	if (cd_arg == NULL || strcmp(cd_arg, "~") == 0)
	{
		return (chdir(home_dir));
	}
	/*if argument is ..*/
	else if (strcmp(cd_arg, "..") == 0)
	{
		return (chdir(".."));
	}
	/*if argument is - return t*/
	else if (strcmp(cd_arg, "-") == 0)
	{
		return (chdir(oldpath));
	}
	else
	{
		return (chdir(cd_arg));
	}
}
