/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int verify_hit_attack(int alpha, int num)
{
	my_printf("%c%c: ", alpha + 'A', num + '0');
	if (navy.my_map[num - 1][alpha] == '.'
	|| navy.my_map[num - 1][alpha] == 'x'
	|| navy.my_map[num - 1][alpha] == 'o') {
		navy.my_map[num - 1][alpha] = 'o';
		my_printf("missed\n");
		if (kill(navy.enemy_pid, SIGUSR1) != 0)
			return (84);
	} else {
		navy.my_map[num - 1][alpha] = 'x';
		my_printf("hit\n");
		navy.my_remaining--;
		if (kill(navy.enemy_pid, SIGUSR2) != 0)
			return (84);
	}
	if (navy.my_remaining == 0)
		navy.game_end = true;
	return (0);
}

int wait_enemy_attack(void)
{
	struct sigaction signal_usr1 = init_sig(&catch_attack_position);
	struct sigaction signal_usr2 = init_sig(&catch_attack_position);

	my_printf("waiting for enemy's attack...\n");
	if (sigaction(SIGUSR1, &signal_usr1, NULL) != 0
	|| sigaction(SIGUSR2, &signal_usr2, NULL) != 0)
		return (84);
	while (navy.attack_end == false);
	navy.attack_end = false;
	return (0);
}
