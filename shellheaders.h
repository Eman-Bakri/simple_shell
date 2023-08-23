#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void prompt_display(char **av, char **env);
char *_envhandle(const char *varenv);
char *_cmdhandle(char *cmd);
char *_mystrsplit(char *str, const char *sprt);
int _printenv();
void _comnthandle(char *input);

#endif

