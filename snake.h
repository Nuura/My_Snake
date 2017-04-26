/*
** snake.h for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:54 2017 SANCHEZ Pierre
** Last update Tue Apr 25 03:08:32 2017 SANCHEZ Pierre
*/

typedef struct  s_carte
{
  char          **map;
  struct carte  *next;
}               t_carte;

typedef struct s_coord
{
  int          xpos;
  int          ypos;
}              t_coord;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int n);
void		read_map(int argc, char *argv[]);
void		generate_map(int argc, char *argv[]);
void		check_arg(int argc, char *argv[]);
int		main(int argc, char *argv[]);
char		**my_tab_in_str2(char *str);
int		display_map(t_coord *s_coord, char **map);
int		move(t_coord *s_coord, t_carte *carte);
