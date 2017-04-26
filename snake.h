/*
** snake.h for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:54 2017 SANCHEZ Pierre
** Last update Mon Apr 24 23:10:47 2017 SANCHEZ Pierre
*/

void		my_putchar(char c);
void		my_putstr(char *str);
char		*my_strcpy(char *dest, char *src);
void		my_put_nbr(int n);
void		read_map(int argc, char *argv[]);
void		generate_map(int argc, char *argv[]);
void		check_arg(int argc, char *argv[]);
int		main(int argc, char *argv[]);

typedef struct	s_carte
{
  char          **map;
  struct carte  *next;
}		t_carte;
