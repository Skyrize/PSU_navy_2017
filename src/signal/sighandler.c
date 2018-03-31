/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

void catch_attack_response(int signum, siginfo_t *info, void *pointer)
{
	if (signum == SIGUSR2) {
		navy.enemy_remaining--;
	}
	if (navy.enemy_remaining == 0)
		navy.game_end = true;
}

void catch_attack_position(int signum, siginfo_t *info, void *pointer)
{
	static int signal_usr1 = 0;
	static int signal_usr2 = 0;
	static int previous_signal = 0;

	if (signum == SIGUSR1 && previous_signal == SIGUSR2) {
		if (verify_hit_attack(signal_usr1, signal_usr2) != 0)
			navy.error_no = 84;
		signal_usr1 = 0;
		signal_usr2 = 0;
		navy.attack_end = true;
		previous_signal = signum;
		return;
	}
	if (signum == SIGUSR1) {
		signal_usr1++;
	} else if (signum == SIGUSR2) {
		signal_usr2++;
	}
	previous_signal = signum;
}

void catch_player_two(int signum, siginfo_t *info, void *pointer)
{
	navy.enemy_pid = info->si_pid;
}
