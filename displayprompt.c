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
{
	char *str = NULL;
	int in, m, wtstatus;
	size_t tu = 0; /*Buffer size*/
	ssize_t charCount;
	char *argv[MAX_COMM];
	char *cmd;
	pid_t chpid; /*child process ID*/

	while (1)
	{
		if (isatty(STDIN_FILENO))
		/*isatty for interactive/non interactive mode check*/
		{
			printf("ENTeam$ ");
			fflush(stdout);
		}
		charCount = getline(&str, &tu, stdin);
		/*Handle EOF*/
		if (charCount == -1)
		{
		free(str);
		exit(EXIT_FAILURE);
		}
		in = 0;
		while (str[in])
		{
			if (str[in] == '\n')
				str[in] = 0;
			in++;
		}
		m = 0;
		argv[m] = _mystrsplit(str, " ");
		while (argv[m])
		{
			argv[++m] = _mystrsplit(NULL, " ");
		}
		/*Handle the exit*/
		if (_strcmp(argv[0], "exit") == 0)
			exit(0);
		/*Handle the env*/
		if (_strcmp(argv[0], "env") == 0)
		{
			_printenv();
		}
		/*Handle the cd command*/
		if (_strcmp(argv[0], "cd") == 0)
		{
		}
		chpid = fork();
		switch (chpid)
		{
			/*if it is a failure*/
			case -1:
				free(str);
				exit(EXIT_FAILURE);
				break;

			/*when successul*/
			case 0:
			/* the parent process never receive 0, 0 always go to child process*/
				cmd = _cmdhandle(argv[0]);
				if (cmd)
				{
					execve(cmd, argv, env);
				}
				if (execve(argv[0], argv, env) == -1)
					printf("%s: No such file or directory\n", av[0]);
				exit(0);
				break;

			default:
				wait(&wtstatus);
				break;
		}
	}
}

