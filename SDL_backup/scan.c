/*
** scan.c for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 12:17:39 2017 SANCHEZ Pierre
** Last update Fri Apr 28 15:28:44 2017 SANCHEZ Pierre
*/

#include "structures.h"

char up()
{
  char dir;
  printf("UP\n");
  return(dir = 'U');
}

char down()
{
  char dir;
  printf("DOWN\n");
  return (dir = 'D');
}

char left()
{
  char dir;
  printf("LEFT\n");
  return (dir = 'L');
}

char right()
{
  char dir;
  printf("RIGHT\n");
  return (dir = 'R');
}

char escape()
{
  printf("ESC\n");
  SDL_Quit();
  exit(0);
}
