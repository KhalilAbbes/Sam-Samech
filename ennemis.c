
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemis.h"


void afficher_ennemis(SDL_Surface *enn,SDL_Surface *screen)
{
SDL_BlitSurface(enn,&positionecran,screen,NULL);
SDL_Flip(screen);
SDL_FreeSurface(enn);

}

void clean(SDL_Surface enn,SDL_Surface screen)
{SDL_FreeSurface(enn);
SDL_FreeSurface(screen);
}

