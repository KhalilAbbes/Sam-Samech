#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

Initialier_ennemi (Init_Ennemi E, SDL_Surface *screen)
{
    E.pos.x=100;
    E.pos.y=200;
	SDL_Surface *image;
    image=SDL_LoadBMP("Ennemi.bmp");
    if(image==NULL)
        {
		printf("Unable to load bitmap: %s\n",SDL_GetError());
		return 1;
		}
	if (E.event ==1)
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		{
			printf("%s",Mix_GetError());
		}
	E.interagir=Mix_LoadMUS("music.mp3");
    }
}

Afficher_Ennemi (Init_Ennemi E,SDL_Surface *screen)
{
    SDL_Surface *image;
    image=SDL_LoadBMP("Ennemi.bmp");
    if(image==NULL)
        {
		printf("Unable to load bitmap: %s\n",SDL_GetError());
		return 1;
		}
    SDL_BlitSurface(E.image,NULL,screen,&E.pos);
    SDL_Flip(screen);
}
