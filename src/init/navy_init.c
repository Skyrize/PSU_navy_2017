/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int init_navy(int nb_args, char **args)
{
	navy.my_remaining = 14;
	navy.enemy_remaining = 14;
	navy.game_end = false;
	navy.attack_end = false;
	navy.error_no = 0;
	switch (nb_args) {
	case 2:
		if (init_player_one(args[1]) != 0)
			return (84);
		break;
	case 3:
		if (init_player_two(my_getnbr(args[1]), args[2]) != 0)
			return (84);
		break;
	default:
		return (84);
	}
	return (0);
}
