#include "main.h"

/**
 * create_file - function that creates a file.
 * @filename: points to the name of the file that we will create.
 * @text_content: points t text that we will write to the file.
 *
 * Return: -1 if the function  fails;
 *         Otherwise 1.
 */

int create_file(const char *filename, char *text_content)
{
	int file, fcreate, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
		{
			length++;
		}
	}

	file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	fcreate = write(file, text_content, length);

	if (file == -1 || fcreate == -1)
	{
		return (-1);
	}
	close(file);
	return (1);
}
