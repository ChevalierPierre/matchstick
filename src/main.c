/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main
*/

#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int memo(char **map)
{
	for (int i = 0 ; map[i] ; i++)
		free(map[i]);
	free(map);
	return 0;
}

char value(int height, int width, int count, int i, int j)
{
	int length = (width + 2) / 2;

	if ((i == 0) || (j == 0) || (i == (height + 1))
	    || (j == (width + 1)))
		return ('*');
	else if ((j <= (length + count)) && (j >= (length - count)))
		return ('|');
	else
		return (' ');
}

char **map_generation(int height)
{
	int count = -1;
	int i = 0;
	int j = 0;
	int width = (2 * height) - 1;
	char **map = NULL;

	if ((map = malloc(sizeof(char *) * (height + 3))) == NULL)
		return NULL;
	for (; i <= (height + 1) ; i++) {
		if ((map[i] = malloc(sizeof(char) * width + 4)) == NULL)
			return NULL;
		for (j = 0 ; j <= (width + 1) ; j++) {
			map[i][j] = value(height, width, count, i, j);
		}
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
		count++;
	}
	map[i] = NULL;
	return (map);
}

int check_args(char **av)
{
	char *str1 = av[1];
	char *str2 = av[2];

	for (int i = 0 ; str1[i] ; i++) {
		if (str1[i] > '9' || str1[i] < '0')
			return 84;
	}
	for (int i = 0 ; str2[i] ; i++) {
		if (str2[i] > '9' || str2[i] < '0')
			return 84;
	}
	if (str1[0] == '0'
	    || str2[0] == '0' || my_getnbr(str1) > 100 || my_getnbr(str1) < 1)
		return 84;
	return 0;
}

int main(int ac, char **av)
{
	int height;
	int max;
	int err = 0;
	char **map = NULL;

	if (ac != 3)
		return 84;
	if (av[1] == NULL || av[2] == NULL)
		return 84;
	if ((err = check_args(av)) == 84)
		return 84;
	height = my_getnbr(av[1]);
	max = my_getnbr(av[2]);
	map = map_generation(height);
	srand(time(0));
	return (game(map, height, max));
}
