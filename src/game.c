/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** game
*/

#include "game.h"
#include <unistd.h>

int check_win_condition(char **map)
{
	for (int i = 0 ; map[i] != NULL ; i++) {
		for (int j = 0 ; map[i][j] != '\0' ; j++) {
			if (map[i][j] == '|')
				return (1);
		}
	}
	return 0;
}

int display(char **map, int height)
{
	for (int i = 0; i < height + 2; i++) {
		 my_putstr(map[i]);
	}
	if (check_win_condition(map) != 0)
		my_putstr("\n");
	return 0;
}

int game(char **map, int height, int max)
{
	display(map, height);
	while (42) {
		turn_message("player");
		if (replace(map, height, max, "player") == 0)
			return 0;
		if (check_win_condition(map) == 0) {
			winning_message("AI");
			return 2;
		}
		turn_message("AI");
		replace(map, height, max, "AI");
		if (check_win_condition(map) == 0) {
			winning_message("player");
			return 1;
		}
	}
	return 84;
}
