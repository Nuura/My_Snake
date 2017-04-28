/*
** main.c for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:07 2017 SANCHEZ Pierre
** Last update Fri Apr 28 01:21:48 2017 SANCHEZ Pierre
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "snake.h"

void		read_map(int argc, char *argv[])
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
}

int		display(int x, char **tab)
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
}

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
      read_map(argc, argv);
    else if (argc == 3)
      generate_map(argc, argv);
  }

  int	main(int argc, char *argv[])
  {
    check_arg(argc, argv);
    return (0);
  }
