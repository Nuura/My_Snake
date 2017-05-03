/*
** main.c for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:07 2017 SANCHEZ Pierre
** Last update Wed May  3 10:38:16 2017 SANCHEZ Pierre
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "snake.h"

int		stock_tab_in_struct(char *argv[])
{
  int		file;
  int		cpt;
  char		memory;
  char		*str;
  t_elem	*s_elem;
  t_carte	*carte;
  t_list	*s_list;
  
  file = open(argv[1], O_RDWR);
  while (read(file, &memory, 1) > 0)
    cpt++;
  str = malloc(sizeof(str) * cpt);
  close(file);
  file = open(argv[1], O_RDWR);
  cpt = 0;
  while (read(file,&memory, 1) > 0)
    {
      str[cpt] = memory;
      cpt++;
    }
  s_list = malloc(sizeof(t_list));
  init_list(s_list);
  s_elem = malloc(sizeof(t_elem));
  carte = malloc(sizeof(t_carte));
  carte->map = my_tab_in_str2(str);
  display(s_elem, s_list, carte->map);
  move(s_elem, s_list, carte);
  return (0);
}

/*void		read_map(int argc, char *argv[])
{
  FILE		*f;
  int		c;
  int		i;
  int		j;
  int		x;
  int		tmp;
  char		**tab;
      
  f = fopen(argv[1], "r");
  i = 0;
  j = 0;
  while (((c = fgetc(f)) != EOF))
    {
      if (c == '\n')
	{
	  i++;
	  tmp = j;
	  j = 0;
	}
      j++;
    }
  fclose(f);
  x = i;
  tab = malloc(sizeof(char *) * (i + 1));
  malloc_tab(tab, i, tmp, argv);
  display(x, tab);
}

void		malloc_tab(char **tab, int i, int tmp, char *argv[])
{
  FILE		*f;
  int		x;
  int		c;
  int		j;

  x = i;
  i = -1;
  j = 0;
  while (i++ <= x)
    tab[i] = malloc(sizeof(char) * (tmp + 1));
  f = fopen(argv[1], "r");
  i = 0;
  while ((c = fgetc(f)) != EOF)
    {
      if (c == '\n')
	{
	  tab[i][j] = c;
	  tab[i][j++] = '\0';
	  i++;
	  j = 0;
	}
      tab[i][j] = c;
      j++;
    }
    }*/

int		display(t_elem *s_elem, t_list *s_list, char **map)
{
  int		i;
  int		j;
  int		s;

  i = 0;
  s = 0;
  while (map[i] != '\0')
    {
      my_putchar('\n');
      j = 0;
      while (map[i][j] != '\0')
	{
	  my_putchar(map[i][j]);
	  if (map[i][j] == 's' && s == 0)
	    {
	      s_list->last = s_elem;
	      s_elem->ypos = i;
	      s_elem->xpos = j;
	      s_elem->next = malloc(sizeof(*s_elem->next));
	      s_elem->next = NULL;
	      s_elem->nb_elem = 0;
	      check_other_snake(s_elem, s_list, map);
	      s++;
	    }
	  j++;
	}
      i++;
    }
  return (0);
}

int		check_other_snake(t_elem *s_elem, t_list *s_list,char **map)
{
  int x;
  int y;
  
  x = -1;
  y = -1;
  if (map[s_elem->ypos][s_elem->xpos + 1]  == 's')
    {
      x = s_elem->xpos + 1;
      y = s_elem->ypos;
    }
  else if (map[s_elem->ypos][s_elem->xpos - 1]  == 's')
    {
      x = s_elem->xpos - 1;
      y = s_elem->ypos;
    }
  else if (map[s_elem->ypos + 1][s_elem->xpos]  == 's')
    {
      x = s_elem->xpos;
      y = s_elem->ypos + 1;
    }
  else if (map[s_elem->ypos - 1][s_elem->xpos] == 's')
    {
      x = s_elem->xpos;
      y = s_elem->ypos - 1;
    }
  if(x != -1 && y != -1)
    {
      add_elem(s_list);
      s_list->last->next->ypos = s_elem->ypos;
      s_list->last->next->xpos = s_elem->xpos + 1;
    }
  /*  my_put_nbr(s_list->last->next->ypos);*/
  return (0);
}
/*int		display(int x, char **tab)
{
  int		i;
  int		j;
  t_coord	*s_coord;
  t_carte	*s_carte;
  i = 0;
  j = 0;
  x = x - 1;
  s_coord = malloc(sizeof(t_coord));
  s_carte = malloc(sizeof(t_carte));
  while (i <= x)
    {
      while (tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  if (tab[i][j] == 's')
	    {
	      s_coord->ypos = i;
	      s_coord->xpos = j;
	    }
	  j++;
	}
      i++;
      j = 0;
    }
  my_putchar('\n');
  move(s_coord, s_carte);
  return (0);
  }*/

  void	 generate_map(int argc, char *argv[])
  {
    if (isdigit(*argv[1]) && isdigit(*argv[2]))
      {
      int ref_l = atoi(argv[1]) -1;
      int ref_h = atoi(argv[2]) - 1;
      int l = ref_l;
      int h = ref_h;
      while (h >= 0) {
	while (l >= 0) {
	  if (l == 0 || l == ref_l || h == 0 || h == ref_h)
	    printf("1");
	  else
	    printf(" ");
	  l--;
	}
	printf("\n");
	l = ref_l;
	h--;
      }
    }
  }

void	check_arg(int argc, char *argv[])
{
  if (argc < 2 || argc > 3)
    printf("Veuillez indiquer le chemin d'une map, ou indiquer sa taille en paramètres\n");
  else if (argc == 2)
    /*read_map(argc, argv);*/
    stock_tab_in_struct(argv);
  else if (argc == 3)
    generate_map(argc, argv);
}

int	main(int argc, char *argv[])
{
  check_arg(argc, argv);
  return (0);
}
