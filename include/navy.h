/*
** EPITECH PROJECT, 2017
** PSU_navy_2017
** File description:
** (enter)
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>

typedef struct player_s
{
	bool current;
	int pid;
	char **map;
} player_t;

typedef struct navy_s
{
	player_t first;
	player_t second;
} navy_t;

///////////////// GLOBAL //////////////////

navy_t navy;

///////////////// DEFINES /////////////////


/////////////// FUNCTIONS ////////////////

int check_help(char *argument);
int start_player_one();
int start_player_two();
struct sigaction init_sig(void (*fptr)());
void catch_player_two(int signum, siginfo_t *info, void *pointer);
int init_navy(int nb_args, char **args);
int init_navy_map(void);
void display_map(char **map);

#endif /* NAVY_H_ */
