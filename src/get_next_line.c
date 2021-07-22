/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** returns the first line of a file given as argument
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_files.h"

static int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return i;
}

static char *realloc_and_write(char *line, char *buff, int *i, int max)
{
	int line_len = my_strlen(line);
	char *ret;
	int n = 0;

	for (i[0] = 0 ; i[0] < max ; i[0]++)
		if (buff[*i] == '\n')
			break;
	if (!(ret = malloc(line_len + *i + 1)))
		return (NULL);
	if (line != NULL) {
		for (n = 0 ; line[n] ; n++)
			ret[n] = line[n];
		free(line);
	}
	for (int j = 0 ; j < *i ; j++)
		ret[n++] = buff[j];
	ret[n] = 0;
	return ret;
}

static char *goto_next_line(char *buff, int start, int max)
{
	int s = start;
	int i = 0;

	for (i = 0 ; i < max - start && buff[i] ; i++)
		buff[i] = buff[s++];
	if (i == 0) {
		free(buff);
		return (NULL);
	}
	for ( ; i < READ_SIZE ; i++)
		buff[i] = 0;
	return (buff);
}

static char *next_line(char *line, char **buff, int i, int fd)
{
	int k = 0;

	do {
		if ((k = read(fd, *buff, READ_SIZE)) <= 0) {
			free(*buff);
			*buff = NULL;
			return ((k == 0 ? line : NULL));
		}
		line = realloc_and_write(line, *buff, &i, k);
	} while (i == READ_SIZE);
	if (i < k)
		*buff = goto_next_line(*buff, i + 1, k);
	else {
		free(*buff);
		*buff = NULL;
	}
	return line;
}

char *get_next_line(int fd)
{
	int i = 0;
	static char *buff = NULL;
	char *line = NULL;

	if (fd < 0 || READ_SIZE < 1)
		return NULL;
	if (buff) {
		line = realloc_and_write(line, buff, &i, READ_SIZE);
		if (i < READ_SIZE && buff[i + 1] != 0) {
			buff = goto_next_line(buff, i + 1, READ_SIZE);
			return line;
		}
	} else
		if ((buff = malloc(READ_SIZE)) == 0)
			return NULL;
	return (next_line(line, &buff, i, fd));
}
