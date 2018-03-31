/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int read_and_place_ships(char **map, char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *line;
	int i = 0;

	if (fd == -1)
		return (84);
	line = my_get_next_line(fd);
	for (; line; i++) {
		if (i > 3)
			return (84);
		if (my_strlen(line) != 7 || place_ship(line, map) != 0)
			return (84);
		free(line);
		line = my_get_next_line(fd);
	}
	if (i != 4)
		return (84);
	close(fd);
}

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

int init_navy_map(char *filepath)
{
	navy.my_map = init_map();
	navy.enemy_map = init_map();
	if (!navy.my_map || !navy.enemy_map)
		return (84);
	if (read_and_place_ships(navy.my_map, filepath) != 0)
		return (84);
	return (0);
}
