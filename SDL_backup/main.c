/*
** main.c for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 11:01:22 2017 SANCHEZ Pierre
** Last update Fri Apr 28 15:28:49 2017 SANCHEZ Pierre
*/

#include "structures.h"

SDL_Renderer  *renderer = NULL;
SDL_Window    *window = NULL;
SDL_Texture   *field_texture = NULL;
SDL_Texture   *fruit_texture = NULL;
SDL_Texture   *head_texture = NULL;
SDL_Texture   *snake_texture = NULL;

char dir;

void		init()
{
  SDL_CreateWindowAndRenderer(1000, 600, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  /*SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);*/
  fruit_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("apple.bmp"));
  head_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("head.bmp"));
  snake_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("snake.bmp"));
  field_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("field.bmp"));
  if (fruit_texture && head_texture && snake_texture && field_texture)
    printf("OK\n");
  head.x = 0;
  head.y = 0;
}

void		command()
{
  const Uint8	*state;
  
  state = SDL_GetKeyboardState(NULL);
  SDL_PumpEvents();
  if (state[SDL_SCANCODE_UP])
    {
      dir = up();
    }
  else if (state[SDL_SCANCODE_DOWN])
    {
      dir = down();
    }
  else if (state[SDL_SCANCODE_LEFT])
    {
      dir = left();
    }
  else if (state[SDL_SCANCODE_RIGHT])
    {
      dir = right();
    }
  else if (state[SDL_SCANCODE_ESCAPE])
    {
      dir = escape();
    }
}

void		display()
{
  SDL_Rect dest;

  SDL_RenderClear(renderer);
  if (dir == 'U')
    head.y--;
  else if (dir == 'D')
    head.y++;
  else if (dir == 'L')
    head.x--;
  else if (dir == 'R')
    head.x++;
  dest.x = head.x;
  dest.y = head.y;
  dest.w = TILE_SIZE;
  dest.h = TILE_SIZE;
  SDL_RenderCopy(renderer,head_texture,NULL,&dest);
  SDL_RenderPresent(renderer);
}

int		main()
{
  int		x;
  init();
  display();
  while (1)
    {
      command();
      display();
      x++;
    }
  return 0;
}
