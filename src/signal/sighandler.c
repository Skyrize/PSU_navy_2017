/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

void catch_player_two(int signum, siginfo_t *info, void *pointer)
{
	navy.second.pid = info->si_pid;
}
