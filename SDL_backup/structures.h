/*
** structures.h for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 11:53:19 2017 SANCHEZ Pierre
** Last update Fri Apr 28 15:14:03 2017 SANCHEZ Pierre
*/

#ifndef _SNAKE_STRUCTURES_H_
#define _SNAKE_STRUCTURES_H_

#include "prototypes.h"

typedef struct	s_pos {
  int		x;
  int		y;
}		t_pos;

t_pos		body;
t_pos		head;
t_pos		tail;
t_pos		fruit;

typedef struct	s_chain {
  int		first;
  int		last;
  int		len;
}		t_chain;

t_chain		snake;

/*
typedef struct	s_func
{
  const Uint8	*flags;
  char		(*funct)();
}		t_func;

t_func		*functions(const Uint8   *state)
{
  t_func		*fc;
  
  if ((fc = malloc(sizeof(t_func)* 6)))
    {
      fc[0].flags = &state[SDL_SCANCODE_UP];
      fc[0].funct = &up;
      fc[1].flags = &state[SDL_SCANCODE_DOWN];
      fc[1].funct = &down;
      fc[2].flags = &state[SDL_SCANCODE_RIGHT];
      fc[2].funct = &left;
      fc[3].flags = &state[SDL_SCANCODE_LEFT];
      fc[3].funct = &right;
      fc[4].flags = &state[SDL_SCANCODE_ESCAPE];
      fc[4].funct = &escape;
      fc[5].flags = NULL;
      fc[5].funct = NULL;
    }
  return (fc);
}
*/
#endif /* !_STRUCTURES_H_ */
