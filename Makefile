##
## EPITECH PROJECT, 2018
## minishell1
## File description:
## Makefile
##

CC		=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I./include -L./lib/my/ -lmy

COV	=	--coverage -lcriterion

RM	=	rm -rf

SRC	=	main.c

SRCTEST	=	sources/my_initializer.c	\
		sources/my_displayer.c	\
		sources/matches_tools.c	\
		sources/artificial_intelligence_functions.c	\
		sources/player_turn_functions.c	\
		tests/check_and_print_lost_sentence_test.c

OBJS	=	$(SRC:.c=.o)

OBJTEST	=	$(SRCTEST:.c=.o)

NAME	=	matchstick

NAME2	=	unit-tests

all: prepare_lib $(NAME)


tests_run:	prepare_lib $(OBJTEST)
	$(CC) -o $(NAME2) $(OBJTEST) $(CFLAGS) $(WFLAGS) $(COV)
	./unit-tests


prepare_lib:
	make -C lib/my


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(WFLAGS) $(CFLAGS)


clean:
	make clean -C lib/my
	$(RM) $(OBJS)
	$(RM) $(OBJTEST)
	$(RM) */*.gcda
	$(RM) */*.gcno
	$(RM) ./*.gcda
	$(RM) ./*.gcno


fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)


re: fclean all
