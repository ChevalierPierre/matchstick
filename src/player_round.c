/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** player round
*/

#include "player_round.h"
#include <unistd.h>
#include <stdlib.h>

int nb_matches(char **map, data_t *data)
{
	int i = 0;

	for (int k = 0 ; map[data->line][k] != '\0' ; k++) {
		if (map[data->line][k] == '|')
			i++;
	}
	return (i);
}

int checking(char **map, int height, int max, char const *name, data_t *data)
{
	if (data->line <= 0 && my_strcmp(name, "line") == 0) {
		error_message("invalid_input", 0);
		return 0;
	} else if (data->matches < 0 && my_strcmp(name, "matches") == 0) {
		error_message("invalid_input", 0);
		return 0;
	} else if ((data->matches > max) && (my_strcmp(name, "matches") == 0)) {
		error_message("maximum", max);
		return 0;
	} else if ((data->matches == 0) && (my_strcmp(name ,"matches") == 0)) {
		error_message("at least", 0);
		return 0;
	} else if ((data->line > height) && (my_strcmp(name ,"line") == 0)) {
		error_message("range", 0);
		return 0;
	} else if ((data->matches > nb_matches(map, data)) && (my_strcmp(name ,"matches") == 0)) {
		error_message("not enough", 0);
		return 0;
	}
	return 1;
}
int line(char **map, int height, int max, data_t *data)
{
	char *str = NULL;

	while (42) {
		my_putstr("Line: ");
		str = get_next_line(0);
		if (str == NULL)
			return 0;
		data->line = my_getnbr(str);
		if (checking(map, height, max, "line", data) == 0)
			continue;
		my_putstr("Matches: ");
		str = get_next_line(0);
		if (str == NULL)
			return 0;
		data->matches = my_getnbr(str);
		if (checking(map, height, max, "matches", data) == 0)
			continue;
		return 1;
	}
}

int player_round(char **map, data_t *data, int height, int max)
{
	if (line(map, height, max, data) == 0)
		return 0;
	map = replace_in_map(map, data, height);
	replacing_message("player", data->matches, data->line);
	display(map, height);
	return 1;
}
