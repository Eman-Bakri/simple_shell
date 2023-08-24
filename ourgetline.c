#include "shellheaders.h"
/**
 * our_getline - Reads a line from a file
 * @lineptr: where the line will be stored
 * @num: stores the buffer size
 * @stream: FILE object
 * Return: number of characters in a line, or -1 on error
 */
ssize_t our_getline(char **lineptr, size_t *num, FILE *stream)
{
	static ssize_t buff_read;
	ssize_t line_len;
	char curr_char = 'x', *buffer;
	int ret;
	/*if buff_read=0,flush stream to ensures buffered data is written to stream*/
	if (buff_read == 0)
		fflush(stream);/*allocate buffer sized 128 characters to store the line*/
	buffer = malloc(sizeof(char) * 128);
	if (!buffer)
		return (-1);/*loop to read characters,if newline exit, otherwise store*/
	while (curr_char != '\n')
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
	/* store a null character at the end of the buffer */
	buffer[buff_read] = '\0';
	/* set the lineptr to the buffe address and the num to size of the buffer */
	*lineptr = buffer;
	*num = buff_read;/* return the number of characters in the line */
	line_len = buff_read;
	if (ret != 0)
		buff_read = 0;
	_comnthandle(buffer);
	return (line_len);
}

