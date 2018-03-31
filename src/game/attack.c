/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int get_attack_response(char stock_coord[2])
{
	struct sigaction signal_usr1 = init_sig(&catch_attack_response);
	struct sigaction signal_usr2 = init_sig(&catch_attack_response);
	int stock_remaining = navy.enemy_remaining;
	int num = stock_coord[1] - '0';
	int alpha = stock_coord[0] - 'A';

	if (sigaction(SIGUSR1, &signal_usr1, NULL) != 0
	|| sigaction(SIGUSR2, &signal_usr2, NULL) != 0)
		return (84);
	nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
	my_printf("%c%c: ", stock_coord[0], stock_coord[1]);
	if (navy.enemy_remaining == stock_remaining) {
		my_printf("missed\n");
		navy.enemy_map[num - 1][alpha] = 'o';
	} else {
		my_printf("hit\n");
		navy.enemy_map[num - 1][alpha] = 'x';
	}
	return (0);
}

int send_attack(char stock_coord[2])
{
	for (int i = 0; i != stock_coord[0] - 'A'; i++) {
		if (kill(navy.enemy_pid, SIGUSR1) != 0)
			return (84);
		nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
	}
	for (int i = 0; i != stock_coord[1] - '0'; i++) {
		if (kill(navy.enemy_pid, SIGUSR2) != 0)
			return (84);
		nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
	}
	if (kill(navy.enemy_pid, SIGUSR1) != 0)
		return (84);
	if (get_attack_response(stock_coord) != 0)
		return (84);
	return (0);
}

int get_attack(char stock_coord[2])
{
	int bytes = 0;
	char line[512];

	my_printf("attack: ");
	bytes = read(0, line, 511);
	if (bytes < 0)
		return (84);
	line[bytes] = 0;
	for (int i = 0; line[i]; i++)
		if (line[i] == '\n')
			line[i] = 0;
	if (check_second_coord(line, stock_coord) != 0) {
		my_printf("wrong position\n");
		get_attack(stock_coord);
	}
	return (0);
}

int attack(void)
{
	char stock_coord[2];

	if (get_attack(stock_coord) != 0)
		return (84);
	if (send_attack(stock_coord) != 0)
		return (84);
	return (0);
}
