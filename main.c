/*
** main.c for  in /home/carra/Desktop/My_Snake/trunk
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 15:29:07 2017 SANCHEZ Pierre
** Last update Mon Apr 24 23:14:52 2017 SANCHEZ Pierre
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "snake.h"

void	read_map(int argc, char *argv[])
{
  FILE		*f;
  int		c;
  int		i;
  char		*tab;
  
  f = fopen(argv[1], "r");
  while (((c = fgetc(f)) != EOF))
    {
      i++;
    }
  fclose(f);
  tab = malloc(sizeof(char *)  * (i +  1));
  f = fopen(argv[1], "r");
  i = 0;
  while ((c = fgetc(f)) != EOF)
    {
      tab[i] = c;
      i++;
    }
  i = 0;
    while (tab[i] != '\0')
    {
      my_putchar(tab[i]);
      i++;
    }
}

void	 generate_map(int argc, char *argv[])
{
  if (isdigit(*argv[1]) && isdigit(*argv[2])) {
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
