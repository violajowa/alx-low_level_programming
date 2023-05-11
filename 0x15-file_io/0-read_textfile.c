#include "main.h"
#include <stdlib.h>

/**
 * @read_textfile: Read the file print out to STDOUT.
 * @filename: the file being read.
 * @letters: letters to be read.
 * Return: fread - the number of bytes read and outputted.
 *         0 - when the filename is NULL or the function fails.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t t;
	ssize_t fread;
	ssize_t file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	t = read(file, buffer, letters);
	fread = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(file);
	return (fread);
}
