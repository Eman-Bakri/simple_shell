#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *buff_read;

ssize_t our_getline(char **lineptr, size_t *num)
{
	/* declare variables */
	ssize_t line_len = 0;
	char curr_char = 'x';

	/* allocate a buffer of size 128 characters to store the line */

	buff_read = malloc(sizeof(char) * 128);
	if (!buff_read)
		return (-1);

	/* loop to read character by character from the stream */
	/* if the character is a newline then exit the loop */
	/* otherwise the character will be stored in the buffer */

	while (curr_char != '\n')
	{
		int ret = read(STDIN_FILENO, &curr_char, 1);
		if (ret == -1)
		{
			free(buff_read);
			return (-1);
		}

		/* if the buffer is full realloc the buffer to be one byte larger */

		if (line_len >= 127)
			buff_read = realloc(buff_read, line_len + 1);

		buff_read[line_len] = curr_char;
		line_len++;
	}

	/* store a null character at the end of the buffer */

	buff_read[line_len] = '\0';

	/* set the lineptr to the buffe address */
	/* and the num to size of the buffer */

	*lineptr = buff_read;
	*num = line_len;

	return (line_len);
}


