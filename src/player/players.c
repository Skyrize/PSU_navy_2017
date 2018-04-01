/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int connect_player_one(void)
{
	struct sigaction signal_catcher = init_sig(&catch_player_two);

	if (sigaction(SIGUSR1, &signal_catcher, NULL) != 0)
		return (84);
	my_printf("my_pid: %d\n", getpid());
	my_printf("waiting for enemy connection...\n");
	pause();
	my_printf("\nenemy connected\n\n");
	return (0);
}

int connect_player_two(int first_player_pid)
{
	my_printf("my_pid: %d\n", getpid());
	if (kill(first_player_pid, SIGUSR1) != 0)
		return (84);
	navy.enemy_pid = first_player_pid;
	my_printf("successfully connected\n\n");
	return (0);
}

int init_player_one(char *filepath)
{
	int error_no = 0;

	if (check_help(filepath) != 0)
		return (1);
	if (connect_player_one() != 0)
		return (84);
	if (init_navy_map(filepath) != 0)
		return (84);
	error_no = process_game(&attack, &wait_enemy_attack);
	if (error_no != 0)
		return (error_no);
	return (0);
}

int init_player_two(int p1_pid, char *filepath)
{
	int error_no = 0;

	if (connect_player_two(p1_pid) != 0)
		return (84);
	if (init_navy_map(filepath) != 0)
		return (84);
	error_no = process_game(&wait_enemy_attack, &attack);
	if (error_no != 0)
		return (error_no);
	return (0);
}
