/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int process_game(int (*fptr1)(), int (*fptr2)())
{
	while (navy.game_end == false) {
		display_positions(navy.my_map, navy.enemy_map);
		my_putchar('\n');
		if (fptr1() != 0 || navy.error_no != 0)
			return (84);
		my_putchar('\n');
		if (navy.game_end == true)
			break;
		if (fptr2() != 0 || navy.error_no != 0)
			return (84);
		my_putchar('\n');
	}
	display_positions(navy.my_map, navy.enemy_map);
	if (navy.enemy_remaining == 0) {
		my_printf("\nI won\n");
	} else {
		my_printf("\nEnemy won\n");
	}
	return (0);
}
