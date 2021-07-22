/*
** EPITECH PROJECT, 2017
**
** File description:
** basic display function
*/

#include <unistd.h>
#include "my_files.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putnbr(int nb)
{
	int mod;

	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	if (nb >= 10) {
		mod = nb % 10;
		nb = (nb - mod) / 10;
		my_putnbr(nb);
		my_putchar(48 + mod);
	} else
		my_putchar(48 + nb % 10);
}
