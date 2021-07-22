/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** player round
*/

#pragma once

#include "main.h"

typedef struct data {
	int matches;
	int line;
	char *str;
} data_t;

int player_round(char **, data_t *data, int, int);
int line(char **map, int height, int max, data_t *);
int checking(char **, int, int, char const *, data_t *);
char **replace_in_map(char **map, data_t *data, int height);
int accurate_line(char **map);
int replace(char **,int ,int, char const *);
int pipe_len(char **map, data_t *data, int height);
int AI_round(char **map, data_t *data, int height, int max);
