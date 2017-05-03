/*
** move.c for  in /home/nuura/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 10:34:20 2017 SANCHEZ Pierre
** Last update Wed May  3 11:42:40 2017 SANCHEZ Pierre
*/
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "snake.h"

char		*readline()
{
  ssize_t	ret;
  char		*buff;
  
  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  free(buff);
  return (buff);
}

/*int		move(t_coord *s_coord, t_carte *carte)
{
  int		z;
  char		*reponse;

  z = 0;
  while (z != 1)
    {
      reponse = readline();
      if (my_strcmp(reponse, "d") == 0)
	move_right(s_coord, carte->map);
      if (my_strcmp(reponse, "a") == 0)
	move_left(s_coord, carte->map);
      if (my_strcmp(reponse, "s") == 0)
	move_down(s_coord, carte->map);
      if (my_strcmp(reponse, "w") == 0)
	{
	  if (s_coord->ypos == 0 && my_strcmp(reponse, "w") == 0)
	    {
	      my_putstr("To Be Continued ... \n");
	      return (0);
	    }
	  else
	    move_up(s_coord, carte->map);
	}
      my_putstr("\e[1;1H\e[2J");
      display(s_coord, carte->map);
      my_putchar('\n');
    }
  free(reponse);
  return (0);
  }*/

void	init_list(t_list *list)
{
  list->nb_link = 1;
  list->first = NULL;
  list->last = NULL;
}

int	add_elem(t_list *list)
{
  t_elem *elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (1);
  list->nb_link++;
  elem->next = NULL;
  list->last->next = malloc(sizeof(t_elem));
  if (list->last->next != NULL)
    list->last->next = elem;
  /*    if (list->first == NULL)*/
  list->first = elem;
  return (0);
}

/*void	detect_snake(char **tab)
{
  int		i;
  int		j;
  t_list	snake;
  int		s;
  i = 0;
  j = 0;
  while (tab[i][j] != '\0')
    {
      if (tab[i][j] == 's')
	{
	  s++;
	  add_elem(snake, s);
	}
      j++;
    }
  i++;
  }*/

int	move_right(t_elem *s_elem, t_list *s_list, char **map)
{
  int x;
  int y;

  
  x = s_list->last->xpos;
  y = s_list->last->ypos;
  map[s_elem->next->ypos][s_elem->next->xpos] = ' ';
  s_elem->next->xpos = x;
  s_elem->next->ypos = y;
  map[s_list->last->ypos][s_list->last->xpos + 1] = 's';
  map[s_elem->next->ypos][s_elem->next->xpos] = 's';
  
  /*map[s_elem->ypos][s_elem->xpos]= ' ';
  map[s_elem->ypos][s_elem->xpos + 1] = 's';
  s_elem->xpos += 1;*/
  return (0);
}

int	move_up(t_elem *s_elem, t_list *s_list, char **map)
{
  int x;
  int y;

  x = s_list->last->xpos;
  y = s_list->last->ypos;
  /*  s_list->last->xpos -= 1;*/
    map[s_elem->next->ypos][s_elem->next->xpos] = ' ';
  s_elem->next->xpos = x;
  s_elem->next->ypos = y;
  /*  map[s_list->last->ypos][s_list->last->xpos]= 's';*/
  map[s_list->last->ypos - 1][s_list->last->xpos] = 's';
  map[s_elem->next->ypos][s_elem->next->xpos] = 's';
  
  /*  map[s_elem->ypos][s_elem->xpos]= ' ';
      map[s_elem->ypos - 1][s_elem->xpos] = 's';*/
  return (0);
}

int	move_down(t_elem *s_elem, t_list *s_list, char **map)
{
  int x;
  int y;
  
  x = s_list->last->xpos;
  y = s_list->last->ypos;
  map[s_elem->next->ypos][s_elem->next->xpos] = ' ';
  s_elem->next->xpos = x;
  s_elem->next->ypos = y;
  map[s_list->last->ypos + 1][s_list->last->xpos] = 's';
  map[s_elem->next->ypos][s_elem->next->xpos] = 's';
  return (0);
}

int	move_left(t_elem *s_elem, t_list *s_list, char **map)
{
  int x;
  int y;

  map[s_elem->next->xpos] = map[s_list->last->xpos];  
  x = s_list->last->xpos;
  y = s_list->last->ypos;
  map[s_elem->next->ypos][s_elem->next->xpos] = ' ';
  s_elem->next->xpos = x;
  s_elem->next->ypos = y;
  map[s_list->last->ypos][s_list->last->xpos - 1] = 's';
  map[s_elem->next->ypos][s_elem->next->xpos] = 's';  
  return (0);
}

int	move(t_elem *s_elem, t_list *s_list, t_carte *carte)
{
  int	z;
  char	*reponse;

  z = 0;
  while (z != 1)
    {
      reponse = readline();
      if (my_strcmp(reponse, "d") == 0)
	move_right(s_elem, s_list, carte->map);
      if (my_strcmp(reponse, "a") == 0)
	move_left(s_elem, s_list, carte->map);
      if (my_strcmp(reponse, "s") == 0)
	move_down(s_elem, s_list, carte->map);
      if (my_strcmp(reponse, "w") == 0)
	move_up(s_elem, s_list, carte->map);
      display(s_elem, s_list, carte->map);
      my_putchar('\n');
    }
  free(reponse);
  return (0);
}


/*int             move_right(t_coord *s_coord, char **map, int i, int j)
{
  map[i][j] = ' ';
  map[i][j + 1] = 's';
  }*/
