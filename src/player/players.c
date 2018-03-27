/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

int start_player_one()
{
	struct sigaction signal_catcher = init_sig(&catch_player_two);

	if (sigaction(SIGUSR1, &signal_catcher, NULL) != 0)
		return (84);
	navy.first.pid = getpid();
	my_printf("my_pid: %d\n", navy.first.pid);
	navy.first.current = true;
	navy.second.current = false;
	my_printf("waiting for enemy connection...\n");
	pause();
	my_printf("\nenemy connected\n");
	return (0);
}

int start_player_two(int first_player_pid)
{
	navy.second.pid = getpid();
	my_printf("my_pid: %d\n", navy.second.pid);
	navy.first.current = false;
	navy.second.current = true;
	if (kill(first_player_pid, SIGUSR1) != 0)
		return (84);
	navy.first.pid = first_player_pid;
	my_printf("successfully connected\n");
	return (0);
}
