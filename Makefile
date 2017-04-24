CC	=		gcc

NAME	=		snake

SRC	=		main.c

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
