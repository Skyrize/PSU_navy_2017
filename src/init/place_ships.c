/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int place_horizontally(char **coords, int start, int end, char **map)
{
	int line = coords[1][1] - '0';

	for (int i = start; i != end + 1; i++) {
		if (map[line - 1][i] != '.')
			return (84);
		map[line - 1][i] = coords[0][0];
	}
	return (0);
}

int place_vertically(char **coords, int start, int end, char **map)
{
	int column = coords[1][0] - 'A';

	for (int i = start; i != end + 1; i++) {
		if (map[i - 1][column] != '.')
			return (84);
		map[i - 1][column] = coords[0][0];
	}
	return (0);
}

int get_horizontal(char **coords, char **map)
{
	int start;
	int end;

	if (coords[1][0] > coords[2][0]) {
		start = coords[2][0] - 'A';
		end = coords[1][0] - 'A';
	} else {
		start = coords[1][0] - 'A';
		end = coords[2][0] - 'A';
	}
	return (place_horizontally(coords, start, end, map));
}

int get_vertical(char **coords, char **map)
{
	int start;
	int end;

	if (coords[1][1] > coords[2][1]) {
		start = coords[2][1] - '0';
		end = coords[1][1] - '0';
	} else {
		start = coords[1][1] - '0';
		end = coords[2][1] - '0';
	}
	return (place_vertically(coords, start, end, map));
}

int place_ship(char *positions, char **map)
{
	char **coords = my_str_to_word_array(positions, ':');

	if (check_invalid_coords(coords) != 0)
		return (84);
	if (coords[1][0] == coords[2][0]) {
		if (get_vertical(coords, map) != 0)
			return (84);
	} else {
		if (get_horizontal(coords, map) != 0)
			return (84);
	}
	return (0);
}
