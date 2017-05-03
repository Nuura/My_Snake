CC	=		gcc

NAME	=		snake

SRC	=		main.c 		\
			move.c		\
			my_putchar.c 	\
			my_putstr.c	\
			my_put_nbr.c	\
			my_strcmp.c	\
			my_tab_in_str.c	\
			snake.h

CFLAGS	=		-Wall -Werror -Wpedantic

OBJ	=		$(SRC:%.c=%.o)

RM	=		rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re $(NAME)
