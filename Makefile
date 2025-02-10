.PHONY: all clean fclean re bonus

NAME = push_swap
NAME_BONUS = checker

INCLUDE = src/push_swap.h
INCLUDE_BONUS = include/push_swap_bonus.h

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	src/sort_commands/pa_pb.c				src/sort_commands/ra_rb_rr.c \
		src/sort_commands/rra_rrb_rrr.c			src/sort_commands/sa_sb_ss.c \
		src/sort_functions/sort_four_five.c		src/sort_functions/sort_maximum.c \
		src/sort_functions/sort_two_three.c		src/sort_functions/sort_utils.c \
		src/utils/errorcheck.c					src/utils/lst_utils.c \
		src/utils/ft_split.c					src/push_swap.c \
		src/utils/ft_split_utils.c				src/utils/utils.c

BONUS_SRC =	bonus/checker_main.c				bonus/get_next_line.c \
			bonus/get_next_line_utils.c			src/sort_commands/ra_rb_rr.c \
			src/sort_commands/rra_rrb_rrr.c		src/sort_commands/sa_sb_ss.c \
			src/sort_commands/pa_pb.c			src/utils/errorcheck.c \
			src/utils/ft_split.c 				bonus/checker_utils.c \
			src/utils/ft_split_utils.c			src/utils/utils.c \
			src/utils/lst_utils.c

OBJ = $(SRC:%.c=obj/%.o)
OBJ_BONUS = $(BONUS_SRC:%.c=obj/%.o)

all: $(NAME)

obj/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ} $(INCLUDE)
	@${CC} ${SRC} -o ${NAME}

bonus: ${OBJ_BONUS} $(INCLUDE_BONUS)
	@${CC} ${BONUS_SRC} -o ${NAME_BONUS}

clean:
		rm -rf obj

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}

re : fclean all
