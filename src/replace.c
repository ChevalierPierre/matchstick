/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** replace
*/

#include "player_round.h"
#include <stdlib.h>

int pipe_len(char **map, data_t *data, int height)
{
	int i = 0;

	for (int k = (2 * height - 1) ; k > 0 ; k--) {
		if (map[data->line][k] == '|')
			i++;
	}
	return (i);
}

int AI_round(char **map, data_t *data, int height, int max)
{
	data->line = accurate_line(map);
	data->matches = random() % max % pipe_len(map, data, height) + 1;
	map = replace_in_map(map, data, height);
	replacing_message("AI", data->matches, data->line);
	display(map, height);
	return 0;
}

int replace(char **map, int height, int max, char const *name)
{
	data_t *data;

	if((data = malloc(sizeof(data))) == NULL)
		return 84;
	data->line = 0;
	data->matches = 0;
	if (my_strcmp(name, "player") == 0)
		return (player_round(map, data, height, max));
	else if (my_strcmp(name, "AI") == 0)
		AI_round(map, data, height, max);
}
