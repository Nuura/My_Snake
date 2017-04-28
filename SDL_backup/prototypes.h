/*
** prototypes.h for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 14:00:20 2017 SANCHEZ Pierre
** Last update Fri Apr 28 14:46:09 2017 SANCHEZ Pierre
*/

#ifndef _SNAKE_PROTOTYPES_H_
#define _SNAKE_PROTOTYPES_H_

#include <stdbool.h>
#include <SDL.h>
#include <stdio.h>

#define TILE_SIZE 32

void	init();
char	up();
char	down();
char	right();
char	left();
char	escape();
void	command();

#endif /* !_SNAKE_PROTOTYPES_H_ */
