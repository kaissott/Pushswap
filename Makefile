.PHONY: all clean fclean re

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	src/sort_commands/pa_pb.c				src/sort_commands/ra_rb_rr.c \
		src/sort_commands/rra_rrb_rrr.c		src/sort_commands/sa_sb_ss.c \
		src/sort_functions/sort_four_five.c	src/sort_functions/sort_maximum.c \
		src/sort_functions/sort_two_three.c	src/sort_functions/sort_utils.c \
		src/utils/errorcheck.c				src/utils/lst_utils.c \
		src/utils/utils.c \
		src/push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c ./src/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re : fclean all
