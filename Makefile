##
## EPITECH PROJECT, 2018
## minishell1
## File description:
## Makefile
##

CC		=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I./include -L./lib/my/ -lmy

RM	=	rm -rf

SRC	=	main.c

OBJS	=	$(SRC:.c=.o)

NAME	=	navy

all: prepare_lib $(NAME)

prepare_lib:
	make -C lib/my

tests_run: prepare_lib
	make -C tests/
	tests/unit-tests

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(WFLAGS) $(CFLAGS)

clean:
	make clean -C lib/my
	make clean -C tests/
	$(RM) $(OBJS)


fclean: clean
	make fclean -C tests/
	make fclean -C lib/my/
	$(RM) $(NAME)


re: fclean all
