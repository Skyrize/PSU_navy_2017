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

typedef struct navy_s
{
	int error_no;
	char **my_map;
	char **enemy_map;
	int enemy_pid;
	int my_remaining;
	int enemy_remaining;
	bool attack_end;
	bool game_end;
} navy_t;

///////////////// GLOBAL //////////////////

navy_t navy;

/////////////// FUNCTIONS ////////////////

/// INIT

struct sigaction init_sig(void (*fptr)());
int init_navy(int nb_args, char **args);
int init_navy_map(char *filepath);
int place_ship(char *positions, char **map);
int init_player_one(char *filepath);
int init_player_two(int p1_pid, char *filepath);

/// WARNINGS

int check_help(char *argument);
int check_invalid_coords(char **coords);
int check_second_coord(char *coord, char stock_coord[2]);

/// CONNECT

int connect_player_one();
int connect_player_two();

/// SIGHANDLERS

void catch_player_two(int signum, siginfo_t *info, void *pointer);
void catch_attack_position(int signum, siginfo_t *info, void *pointer);
void catch_attack_response(int signum, siginfo_t *info, void *pointer);

/// GAME

int process_game(int (*fptr1)(), int (*fptr2)());
void display_map(char **map);
void display_positions(char **my_map, char **enemy_map);
int wait_enemy_attack(void);
int attack(void);
int get_attack(char stock_coord[2]);
int send_attack(char stock_coord[2]);
int verify_hit_attack(int alpha, int num);

#endif /* NAVY_H_ */
