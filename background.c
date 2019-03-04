#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

void initialiser_background(background *b,char m[],SDL_Surface *screen)
{
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("Unable t initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(800,600,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL){
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;}
b->img=IMG_Load("");
if (back==NULL)
{printf("Error Loading ");
        return 1;}

b->pos.x=0;
b->pos.y=0;
b->pos.w=b->img->w;
b->pos.h=b->img->h;
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}
b->son=Mix_LoadMUS(m)
}

void afficher_background(background *b,SDL_Surface *screen)
{ blitsurface(b.img,&b->positionback,screen,NULL);
  Mix_PlayMusic(b->son,-1);
 SDL_flip(screen);
}
