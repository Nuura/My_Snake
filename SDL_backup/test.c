/*                                                                                                 
** main.c for snake in /home/carra/Desktop/Snake                                                     
**                                                                                                   
** Made by SANCHEZ Pierre                                                                            
** Login   <sanche_p@etna-alternance.net>                                                            
**                                                                                                   
** Started on  Tue Apr 25 00:32:54 2017 SANCHEZ Pierre                                               
** Last update Thu Apr 27 10:18:14 2017 SANCHEZ Pierre
*/

#include "prototypes.h"

SDL_Window      *init_window()
{
  SDL_Window* pWindow;
  pWindow = NULL;
  /* Initialisation simple */
  if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      return pWindow;
    }

  {
    /* Création de la fenêtre */
    SDL_Window* pWindow;
    pWindow = SDL_CreateWindow("Ma première application SDL2",
			       SDL_WINDOWPOS_UNDEFINED,
			       SDL_WINDOWPOS_UNDEFINED,
			       640,
			       480,
			       (SDL_WINDOW_SHOWN));

    if( pWindow )
      {
	SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */
      }
    else
      {
	fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
      }
  }

}

void setFullscreen(SDL_Window *pWindow)
{
  int quit;
  int fullscreen;
  SDL_Event event;

  quit = 0;
  fullscreen = 0;

  while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
    {
      switch(event.type)
	{
	case SDL_QUIT: // Clic sur la croix
	  quit=1;
	  break;
	case SDL_KEYUP: // Relâchement d'une touche
	  if ( event.key.keysym.sym == SDLK_f ) // Touche f
	    {
	      // Alterne du mode plein écran au mode fenêtré
	      if ( fullscreen == 0 )
		{
		  fullscreen = 1;SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);

		}
	      else if ( fullscreen == 1 )
		{
		  fullscreen = 0;
		  SDL_SetWindowFullscreen(pWindow,0);
		}
	    }
	  break;
	}
    }
}



int main(int argc, char** argv)
{
  SDL_Surface *surface;
  SDL_Window* pWindow;

  pWindow = init_window();
  setFullscreen(pWindow);
  SDL_Surface* pSprite = SDL_LoadBMP("character.bmp");
  if ( pSprite )
  {
    SDL_Rect dest = { 640/2 - pSprite->w/2,480/2 - pSprite->h/2, 0, 0};
    SDL_BlitSurface(pSprite,NULL,SDL_GetWindowSurface(pWindow),&dest); // Copie du sprite
    
    SDL_UpdateWindowSurface(pWindow);
    // Mise à jour de la fenêtre pour prendre en compte la copie du sprite
    SDL_Delay(3000); // Attendre trois secondes, que l'utilisateur voit la fenêtre
    
    SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
  }
  else
    {
      fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }
  
  SDL_Delay(3000);
  printf("End\n");
  SDL_DestroyWindow(pWindow);
  SDL_Quit();

  return 0;
}
