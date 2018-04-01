/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

void init_values(void)
{
	navy.my_remaining = 14;
	navy.enemy_remaining = 14;
	navy.game_end = false;
	navy.attack_end = false;
	navy.error_no = 0;
}

int init_navy(int nb_args, char **args)
{
	int error_no = 0;

	init_values();
	switch (nb_args) {
	case 2:
		error_no = init_player_one(args[1]);
		if (error_no != 0)
			return (error_no);
		break;
	case 3:
		error_no = init_player_two(my_getnbr(args[1]), args[2]);
		if (error_no != 0)
			return (error_no);
		break;
	default:
		return (84);
	}
	return (0);
}
