/*
** scan.c for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 12:17:39 2017 SANCHEZ Pierre
** Last update Thu Apr 27 12:36:25 2017 SANCHEZ Pierre
*/

#include "prototypes.h"
#include "structures.h"

int up()
{
  printf("UP\n");
  return(dir = UP);
}
int down()
{
  printf("DOWN\n");
  return (dir = DOWN);
}
int left()
{
  printf("LEFT\n");
  return (dir = LEFT);
}
int right()
{
  printf("RIGHT\n");
  return (dir = RIGHT);
}

int escape()
{
  printf("ESC\n");
  exit(0);
}
