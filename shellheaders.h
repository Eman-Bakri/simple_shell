#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern char **environ;

char *prog_name;
char *cmd_name;

void prompt_display(char **av, char **env);
char *_envhandle(const char *varenv);
char *_cmdhandle(char *cmd);
char *_mystrsplit(char *str, const char *sprt);
int _printenv(void);
void _comnthandle(char *input);
ssize_t our_getline(char **lineptr, size_t *num, FILE *stream);
char *got_command(char *cmd);
void print_prompt(void);
int split_input(char *input, char *argv[]);
void handle_err(char *str);
void print_error(void);

unsigned int _strlen(const char *str);
char *_strcat(char *deststr, const char *srcstr);
char *_strcpy(char *deststr, const char *srcstr);
int _strcmp(const char *str1, const char *str2);

#endif

