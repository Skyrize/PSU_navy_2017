/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

void replace_char(char *str, char seeked, char replacement)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == seeked)
			str[i] = replacement;
	}
}
