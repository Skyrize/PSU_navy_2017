/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int main(int ac, char **av)
{
	int error_no = init_navy(ac, av);

	if (error_no == 1)
		return (0);
	else if (error_no != 0)
		return (84);
	return (0);
}
