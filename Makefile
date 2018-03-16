NAME = lchety.filler
CC = clang
SRC =	main.c							\
		reset.c							\
		parsing.c						\
		play.c							\
		check_move.c					\
		piece.c

INC = -I includes -I libft/includes

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) $(OBJ) $(INC) libft/libft.a -o $(NAME)

%.o : srcs/%.c includes/filler.h
	$(CC) $(FLAGS) -c $< $(INC) -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
