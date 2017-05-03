/*
** prototypes.h for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Mon Apr 24 14:00:20 2017 SANCHEZ Pierre
** Last update Thu Apr 27 12:35:27 2017 SANCHEZ Pierre
*/

#ifndef _SNAKE_PROTOTYPES_H_
#define _SNAKE_PROTOTYPES_H_

#include <stdbool.h>
#include <SDL.h>
#include <stdio.h>

#define LEFT  1
#define UP    2
#define DOWN  3
#define RIGHT 4
#define MAX_X 24
#define MAX_Y 14
#define TILE_SIZE 32

void	init();
int	up();
int	down();
int	right();
int	left();
int	escape();

#endif /* !_SNAKE_PROTOTYPES_H_ */
