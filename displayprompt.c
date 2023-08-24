#include "shellheaders.h"
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMM 10
/**
 * prompt_display - display a prompt msg
 * and ask user for input
 * @av: argument value
 * @env: envirnment var
 * Return: void
 *
*/
void prompt_display(char **av, char **env)
{	char *str = NULL, *argv[MAX_COMM], *cmd;
	int m, wtstatus;
	pid_t chpid; /*child process ID*/

	while (1)
	{
		if (isatty(STDIN_FILENO))/*isatty for interact/non interact mode check*/
		{	write(1, "ENteam$ ", 8);
			fflush(stdout);
		}
		str = got_command(str);
		m = 0;
		argv[m] = _mystrsplit(str, " ");
		while (argv[m])
			argv[++m] = _mystrsplit(NULL, " ");
		if (_strcmp(argv[0], "exit") == 0)/*Handle the exit*/
			exit(0);
		if (_strcmp(argv[0], "env") == 0)/*Handle the env*/
		{	_printenv();
			continue;
		}
		chpid = fork();
		switch (chpid)
		{	case -1:free(str);
				exit(EXIT_FAILURE);
				break;
			case 0:
				cmd = _cmdhandle(argv[0]);
				if (cmd)
					execve(cmd, argv, env);
				if (execve(argv[0], argv, env) == -1)
					printf("%s: No such file or directory\n", av[0]);
				free(cmd);
				break;
			default:
				wait(&wtstatus);
				if (wtstatus != 0)
					exit(127);
				break;
		}
	}
}
/**
 * got_command - got command from user
 * @cmd: command
 * Return: str
*/
char *got_command(char *cmd)
{
	char *str = NULL;
	size_t tu = 0; /*Buffer size*/
	ssize_t charCount;
	int in;

	charCount = our_getline(&str, &tu, stdin);
	/*Handle EOF*/
	if (charCount == -1)
	{
		free(str);
		free(cmd);
		exit(0);
	}
	in = 0;
	while (str[in])
	{
		if (str[in] == '\n')
			str[in] = 0;
		in++;
	}
	return (str);
}
