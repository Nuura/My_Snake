/*
** move.c for  in /home/nuura/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 10:34:20 2017 SANCHEZ Pierre
** Last update Thu Apr 27 20:32:21 2017 SANCHEZ Pierre
*/
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "snake.h"

/*char		*readline()
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
  }*/

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
  list = malloc(sizeof(t_list));
  list->nb_link = 0;
  list->first = NULL;
  list->last = NULL;
}