/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#include "my.h"
#include "navy.h"

struct sigaction init_sig(void (*fptr)())
{
	struct sigaction sig;

	sig.sa_sigaction = fptr;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	return (sig);
}
