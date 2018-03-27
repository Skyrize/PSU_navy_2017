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
	switch (nb_args) {
	case 2:
		if (check_help(args[1]) != 0)
			return (1);
		if (start_player_one() != 0)
			return (84);
		break;
	case 3:
		if (start_player_two(my_getnbr(args[1])) != 0)
			return (84);
		break;
	default:
		return (84);
	}
	if (init_navy_map() != 0)
		return (84);
	return (0);
}
