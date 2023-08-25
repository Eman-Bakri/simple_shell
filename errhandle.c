#include "shellheaders.h"
/**
 * handle_err - handle error message
 * @str: string to take
 * Return: void
*/
void handle_err(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}
/**
 * print_err - printing error
 * Return: void
*/
void print_error(void)
{
	handle_err(prog_name);
	handle_err(": ");
	handle_err(cmd_name);
	handle_err(": ");
	handle_err("command not found\n");
}

