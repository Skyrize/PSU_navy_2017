/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int check_first_coord(char *coord)
{
	int nb = 0;
	static bool boat_sizes[4] = {false, false, false, false};

	if (my_strlen(coord) != 1)
		return (84);
	nb = my_getnbr(coord);
	if (nb < 2 || nb > 5)
		return (84);
	if (boat_sizes[nb - 2] == true)
		return (84);
	else
		boat_sizes[nb - 2] = true;
	return (0);
}

int check_second_coord(char *coord, char stock_coord[2])
{
	if (my_strlen(coord) != 2)
		return (84);
	stock_coord[0] = coord[0];
	if (stock_coord[0] < 'A' || stock_coord[0] > 'H')
		return (84);
	stock_coord[1] = coord[1];
	if (stock_coord[1] < '1' || stock_coord[1] > '8')
		return (84);
	return (0);
}

int check_coords_len(int len, int start, int end)
{
	int real_len = end - start;

	if (real_len < 0)
		real_len = -real_len;
	if (real_len + 1 != len)
		return (84);
	return (0);
}

int check_invalid_coords_alpha_num(char stock_coord_02[2],
	char stock_coord_03[2], int len)
{
	if (stock_coord_02[0] != stock_coord_03[0]) {
		if (stock_coord_02[1] != stock_coord_03[1])
			return (84);
		else
			return (check_coords_len(len, stock_coord_02[0] - 'A',
				stock_coord_03[0] - 'A'));
	} else {
		if (stock_coord_02[1] == stock_coord_03[1])
			return (84);
		else
			return (check_coords_len(len, stock_coord_02[1] - '0',
				stock_coord_03[1] - '0'));
	}
	return (0);
}

int check_invalid_coords(char **coords)
{
	char stock_coord_02[2] = {0, 0};
	char stock_coord_03[2] = {0, 0};

	if (!coords || !coords[0] || !coords[1] || !coords[2])
		return (84);
	if (check_first_coord(coords[0]) != 0)
		return (84);
	if (check_second_coord(coords[1], stock_coord_02) != 0)
		return (84);
	if (check_second_coord(coords[2], stock_coord_03) != 0)
		return (84);
	if (check_invalid_coords_alpha_num(stock_coord_02, stock_coord_03,
		my_getnbr(coords[0])) != 0)
		return (84);
	return (0);
}
