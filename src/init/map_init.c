/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

char **init_map(void)
{
	char **map = malloc(sizeof(char *) * 9);
	char *empty_line = "........";

	if (!map)
		return (NULL);
	for (int i = 0; i != 8; i++) {
		map[i] = my_strdup(empty_line);
		if (!map[i])
			return (NULL);
	}
	map[8] = NULL;
	return (map);
}

int init_navy_map(void)
{
	navy.first.map = init_map();
	navy.second.map = init_map();
	if (!navy.first.map || !navy.second.map)
		return (84);
	return (0);
}
