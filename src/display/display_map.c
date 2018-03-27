/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

void display_map(char **map)
{
	my_printf(" |A B C D E F G H\n");
	my_printf("-+---------------\n");
	for (int i = 0; map[i]; i++) {
		my_printf("%d|%c", i + 1, map[i][0]);
		for (int j = 1; map[i][j]; j++)
			my_printf(" %c", map[i][j]);
		my_printf("\n");
	}
}
