/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int check_help(char *argument)
{
	if (my_strcmp(argument, "-h") == 0
	|| my_strcmp(argument, "--help") == 0) {
		my_printf("USAGE\n\t./navy [first_player_pid] navy_positions");
		my_printf("\nDESCRIPTION\n\tfirst_player_pid: only for the ");
		my_printf("2nd player. pid of the first player.\n\tnavy_posit");
		my_printf("ions: file representing the positions of the ships");
		my_printf(".\n");
		return (1);
	}
	return (0);
}
