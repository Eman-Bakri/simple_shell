#include "shellheaders.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * our_getline - Reads a line from a file
 *
 * @lineptr: where the line will be stored
 * @num: stores the buffer size
 * @stream: FILE object
 *
 * Return: number of characters in a line, or -1 on error
 */

ssize_t our_getline(char **lineptr, size_t *num, FILE *stream)
{
	/* the buff_read stores the number of characters read from the stream */
	static ssize_t buff_read;
	ssize_t line_len;
	char curr_char = 'x', *buffer;
	int ret;

	if (buff_read == 0)/* if buff_read 0, flush stream so buff data is written */
		fflush(stream);
	buffer = malloc(sizeof(char) * 128);/* alloc buff size 128 to store line */
	if (!buffer)
		return (-1);
	/* if the char is a newline then exit the loop */
	while (curr_char != '\n')/* otherwise char will be stored in buff */
	{
		ret = read(STDIN_FILENO, &curr_char, 1);
		if (ret == -1 || (ret == 0 && buff_read == 0))
		{
			free(buffer);
			return (-1);
		}
		if (ret == 0 && buff_read != 0)
		{
			buff_read++;
			break;
		}
		/* if the buffer is full realloc the buffer to be one byte larger */
		if (buff_read >= 127)
			buffer = realloc(buffer, buff_read + 1);

		buffer[buff_read] = curr_char;
		buff_read++;
	}
	buffer[buff_read] = '\0';/* store a null char at end of buffer */
	*lineptr = buffer;/* set the lineptr to the buffer address */
	*num = buff_read;/* set the num to size of the buffer */
	line_len = buff_read;/* return the number of characters in the line */
	if (ret != 0)
		buff_read = 0;
	_comnthandle(buffer);
	return (line_len);
}

