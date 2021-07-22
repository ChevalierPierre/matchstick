##
## EPITECH PROJECT, 2017
## EPITECH
## File description:
## Makefile screensaver
##

CC	=	gcc

CFLAGS	+=	-Wextra -Wall -W

CFLAGS	+=	-Iinclude

CRIFLAGS	+=	-lcriterion

CRIFLAGS	+=	-lgcov

RM	=	rm -f

NAME	=	matchstick

SRC	=	src/main.c	\
		src/get_next_line.c	\
		src/my_getnbr.c	\
		src/game.c	\
		src/messages.c	\
		src/my_strcmp.c	\
		src/my_put.c	\
		src/replace.c	\
		src/player_round.c	\
		src/replace_in_map.c

OBJ	=	$(SRC:.c=.o)

TEST	=	unit_tests

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)
	$(RM) $(TEST)

re:	fclean all

tests_run:
		$(CC) --coverage -c tests/*.c
		$(CC) *.o -lcriterion -lgcov -o $(TEST)
		./$(TEST)

.PHONY:	all clean fclean re
