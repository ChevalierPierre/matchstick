/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** compares two strings and returns an int in function
*/

int my_strlen(char const *str);

int min_value(int nb1, int nb2)
{
	return (nb1 < nb2 ? nb1 : nb2);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int s1_len = my_strlen(s1) - 1;
	int s2_len = my_strlen(s2) - 1;
	int min_len = min_value(s1_len, s2_len);

	while ((s1[i] == s2[i]) && (i <= min_len))
		i++;
	if (s1[i] < s2[i])
		return (-1);
	else if (s1[i] > s2[i])
		return (1);
	return (0);
}
