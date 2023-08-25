#include "shellheaders.h"

/**
 * _envhandle - get env var and divide by =
 * @varenv: env variable
 * Return: var or NULL
*/
char *_envhandle(const char *varenv)
{
	int in = 0;
	char *q;

	while (environ[in])
	{
		q = _mystrsplit(environ[in], "=");
		if (_strcmp(varenv, q) == 0)
			return (_mystrsplit(NULL, "\n"));
		in++;
	}
	return (NULL);
}
/**
 * _printenv - output env builtin var
 *
 * Return: 0 Sucess
*/
int _printenv(void)
{
	int m = 0;

	while (environ[m])
	{
		write(STDOUT_FILENO, environ[m], strlen(environ[m]));
		write(STDOUT_FILENO, "\n", 1);
		m++;
	}
	return (0);
}
/**
 * _cmdhandle - handle comands
 * including path variable
 * @cmd: command to be handled
 * Return: full command or NULL
*/
char *_cmdhandle(char *cmd)
{
	char *_path = _envhandle("PATH");
	char *tkn; /*Token variable*/
	char *_fullcmd;

	tkn = _mystrsplit(_path, ":");
	while (tkn)
	{
		_fullcmd = malloc(_strlen(tkn) + _strlen(cmd) + 2);
		_strcpy(_fullcmd, tkn);
		_strcat(_fullcmd, "/");
		_strcat(_fullcmd, cmd);
		if (access(_fullcmd, X_OK) == 0)
			return (_fullcmd);
		free(_fullcmd);
		tkn = _mystrsplit(NULL, ":");
	}
	free(tkn);
	return (NULL);
}
/**
 * _exitexc - execute exit
 * @args: arguments
 * Return: status 0 Sucess
*/
int _exitexc(char **args)
{
	int st;

	if (args[1] == NULL)
		st = 0;
	else
		st = atoi(args[1]);
	exit(st);
}

/**
 * _envset - set a new env var
 * @name: variable name
 * @val: variable value
 * @ovwr: overwrite
 * Return: 0 Success
*/
int _envset(const char *name, const char *val, int ovwr)
{
	int m = 0;
	char *varnew;
	if (!name || !val)
		return (-1);
	while (environ[m])
	{
		if (_strcmp(environ[m], name) == 0)
		{
			if (ovwr)
			{
				varnew = malloc(_strlen(name) + _strlen(val) + 2);
				_strcpy(varnew, name);
				_strcat(varnew, "=");
				_strcat(varnew, val);
				environ[m] = varnew;
				return (0);
			}
			return(0);
		}
		m++;
	}
	varnew = malloc(_strlen(name) + _strlen(val) + 2);
	_strcpy(varnew, name);
	_strcat(varnew, "=");
	_strcat(varnew, val);
	environ[m] = varnew;
	environ[m + 1] = NULL;
	return (0);
}

