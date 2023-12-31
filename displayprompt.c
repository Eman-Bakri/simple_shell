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
	int wtstatus, line_count = 0;
	pid_t chpid; /*child process ID*/

	while (1)
	{
		print_prompt();
		str = got_command(str);
		line_count += 1;
		split_input(str, argv);
		if (strcmp(argv[0], "exit") == 0)/*Handle the exit*/
			_exitexc(av);
		if (strcmp(argv[0], "setenv") == 0)/*Handle the senenv*/
			_envset(argv[1], argv[2], 1);
		if (strcmp(argv[0], "env") == 0)/*Handle the env*/
		{	_printenv();
			continue;
		}
		if (strcmp(argv[0], "cd") == 0)/*Handle the cd*/
			own_cd(argv[1]);
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
					printf("%s: %d: %s: not found\n", av[0], line_count, str);
				exit(0);
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
	if (charCount == -1 || charCount == EOF)
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
	free(cmd);
	return (str);
}
/**
 * print_prompt - print the prompt
 * Return: void
*/
void print_prompt(void)
{
	if (isatty(STDIN_FILENO)) /*for interact/non interact mode check*/
	{
		write(1, "($) ", 4);
		fflush(stdout);
	}
}
/**
 * split_input - split the given input
 * @input: entered input
 * @argv: argument value
 * Return: argc value
*/
int split_input(char *input, char *argv[])
{
	int argc = 0;
	char *token;

	token = _mystrsplit(input, " ");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = _mystrsplit(NULL, " ");
	}
	return (argc);
}

