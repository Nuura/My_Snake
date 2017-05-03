/*
** snake.h for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:54 2017 SANCHEZ Pierre
** Last update Wed May  3 10:17:12 2017 SANCHEZ Pierre
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

typedef struct s_list
{
  int		nb_link;
  struct s_elem *first;
  struct s_elem *last;
}	       t_list;

typedef struct s_elem
{
  int		nb_elem;
  int		xpos;
  int		ypos;
  struct s_elem *next;
}	       t_elem;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int n);
int		my_strcmp(char *s1, char *s2);
void		read_map(int argc, char *argv[]);
void		generate_map(int argc, char *argv[]);
void		check_arg(int argc, char *argv[]);
int		main(int argc, char *argv[]);
char		**my_tab_in_str2(char *str);
int		display_map(t_elem *s_elem, char **map);
/*int		display(int x, char **tab);*/
int             display(t_elem *s_elem, t_list *s_list, char **map);
void            malloc_tab(char **tab, int i, int tmp, char *argv[]);
char            *readline();
int		move(t_elem *s_elem, t_list *s_list, t_carte *s_carte);
int		move_up(t_elem *s_elem, t_list *s_list, char **map);
int		move_right(t_elem *s_elem, t_list *s_list, char **map);
int		move_down(t_elem *s_elem, t_list *s_list, char **map);
int		move_left(t_elem *s_elem, t_list *s_list, char **map);

int             stock_tab_in_struct(char *argv[]);
int             check_other_snake(t_elem *s_elem, t_list *s_list, char **map);
int		add_elem(t_list *list);
void		init_list(t_list *list);
