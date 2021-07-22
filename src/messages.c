/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** message
*/

#include "message.h"

int winning_message(char const *name)
{
	if (my_strcmp(name, "AI") == 0) {
		my_putstr("You lost, too bad...\n");
		return 2;
	}
	else if (my_strcmp(name, "player") == 0) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return 1;
	}
	return 84;
}

int replacing_message(char const *name, int matches, int line)
{
	my_putstr(name);
	my_putstr(" removed ");
	my_putnbr(matches);
	my_putstr(" match(es) from line ");
	my_putnbr(line);
	my_putstr("\n");
	return 0;
}

int turn_message(char const *name)
{
	if (my_strcmp(name, "AI") == 0) {
		my_putstr("AI's turn...\n");
		return 0;
	} else if (my_strcmp(name, "player") == 0) {
		my_putstr("Your turn:\n");
		return 0;
	}
	return 84;
}

int error_message(char const *name, int number)
{
	if (my_strcmp(name, "range") == 0) {
		my_putstr("Error: this line is out of range\n");
		return 0;
	} else if (my_strcmp(name, "maximum") == 0) {
		my_putstr("Error: you cannot remove more than ");
		my_putnbr(number);
		my_putstr(" matches per turn\n");
		return 0;
	} else if (my_strcmp(name, "invalid_input") == 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return 0;
	} else if (my_strcmp(name, "at least") == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return 0;
	} else if (my_strcmp(name, "not enough") == 0) {
		my_putstr("Error: not enough matches on this line\n");
		return 0;
	}
	my_putstr("error message not found");
	return 84;
}
