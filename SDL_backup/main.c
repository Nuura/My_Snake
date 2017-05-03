/*
** main.c for snake in /home/carra/Desktop/Snake
** 
** Made by SANCHEZ Pierre
** Login   <sanche_p@etna-alternance.net>
** 
** Started on  Thu Apr 27 11:01:22 2017 SANCHEZ Pierre
** Last update Thu Apr 27 12:42:07 2017 SANCHEZ Pierre
*/

#include "prototypes.h"
#include "structures.h"

SDL_Renderer  *renderer = NULL;
SDL_Window    *window = NULL;
SDL_Texture   *field_texture = NULL;
SDL_Texture   *fruit_texture = NULL;
SDL_Texture   *head_texture = NULL;
SDL_Texture   *snake_texture = NULL;

char dir;
char old_dir;

void		init()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
    }
  else
    {
      SDL_CreateWindowAndRenderer(800, 480, 0, &window, &renderer);
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderClear(renderer);
      SDL_RenderPresent(renderer);
      fruit_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("apple.bmp"));
      head_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("head.bmp"));
      snake_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("snake.bmp"));
      field_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("field.bmp"));
      if (fruit_texture && head_texture && snake_texture && field_texture)
	printf("OK\n");
    }
}

void display()
{
  int		n;
  t_func	*fc;

  n = 0;
  fc = funcs(state);
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  SDL_PumpEvents();
  while (!fc[n].flags)
    {
      n++;
    }
  dir = fc[n].funct();
  printf("%d\n", dir);
  /*
  if (state[SDL_SCANCODE_UP])
    {
      printf("UP\n");
      dir = UP;
    }
  else if (state[SDL_SCANCODE_DOWN])
    {
      printf("DOWN\n");
      dir = DOWN;
    }
  else if (state[SDL_SCANCODE_LEFT])
    {
      printf("LEFT\n");
      dir = LEFT;
    }
  else if (state[SDL_SCANCODE_RIGHT])
    {
      printf("RIGHT\n");
      dir = RIGHT;
    }
  else if (state[SDL_SCANCODE_ESCAPE])
    {
      printf("ESC\n");
      exit(0);
      }
*/
  /* Ignore opposite direction */
  if (dir + old_dir != 5 || snake.len == 1)
    {
      old_dir = dir;
    }
  else
    {
      dir = old_dir;
    }
}

int		main()
{
  init();
  display();
  while (1)
    {
      /*checkline();
	if (update()) {
	gameover();
	}*/
      display();
      SDL_Delay(16 * 10);
    }
  SDL_Delay(3000);
  SDL_Quit();
  printf("End\n");
  return 0;
}
