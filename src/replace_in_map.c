/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** replace in map
*/

#include "player_round.h"

int accurate_line(char **map)
{
	for (int j = 0; map[j]; j++) {
		for (int i = 0 ; map[j][i] ; i++) {
			if (map[j][i] == '|')
				return (j);
		}
	}
	return (84);
}

char **replace_in_map(char **map, data_t *data, int height)
{
	int j = data->matches;
	int k = (2 * height - 1) - (height - data->line);

	while (j > 0) {
		if (map[data->line][k] == '|') {
			map[data->line][k] = ' ';
			k--;
			j--;
		}
		else
			k--;
		if (k == 0)
			return (map);

	}
	return (map);
}
