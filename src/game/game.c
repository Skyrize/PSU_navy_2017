/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int game_loop(int (*fptr1)(), int (*fptr2)())
{
	int error_no = 0;

	while (navy.game_end == false) {
		display_positions(navy.my_map, navy.enemy_map);
		my_putchar('\n');
		error_no = fptr1();
		if (error_no != 0 || navy.error_no != 0)
			return (error_no);
		my_putchar('\n');
		if (navy.game_end == true)
			break;
		error_no = fptr2();
		if (error_no != 0 || navy.error_no != 0)
			return (error_no);
		my_putchar('\n');
	}
	return (0);
}

int process_game(int (*fptr1)(), int (*fptr2)())
{
	int error_no = game_loop(fptr1, fptr2);

	if (error_no != 0)
		return (error_no);
	display_positions(navy.my_map, navy.enemy_map);
	if (navy.enemy_remaining == 0) {
		my_printf("\nI won\n");
	} else {
		my_printf("\nEnemy won\n");
	}
	return (0);
}
