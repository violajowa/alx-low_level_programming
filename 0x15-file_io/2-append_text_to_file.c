#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename:points to the name of the file.
 * @text_content: text to append to the end of the file.
 *
 * Return: -1 if filename is NULL or function fails.
 *         or the file does not exist or the user lacks write permissions;
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fopen, fwrite, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
		{
			length++;
		}
	}

	fopen = open(filename, O_WRONLY | O_APPEND);
	fwrite = write(fopen, text_content, length);

	if (fopen == -1 || fwrite == -1)
	{
		return (-1);
	}
	close(fopen);
	return (1);
}
