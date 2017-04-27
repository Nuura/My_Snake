CC	=		gcc

NAME	=		snake

SRC	=		main.c	\
			scan.c

CFLAGS	=		-Wall -Werror -Wpedantic

OBJ	=		$(SRC:%.c=%.o)

RM	=		rm -f

SDL	=		sdl2-config --cflags --libs

all:			$(NAME)

$(NAME):	
			$(CC) $(FLAGS) -o  $(NAME) $(SRC) `$(SDL)`

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re $(NAME)
