
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

int initialiser_background(background *b,char m[], SDL_Surface *screen)
{
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(800,600,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
b->image=SDL_LoadBMP("background.bmp ");
if (b->image==NULL)
{ 
printf("Error Loading ");
        return 1;
}

b->pos.x=0;
b->pos.y=0;
b->pos.w=b->image->w;
b->pos.h=b->image->h;
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());}

Mix_Music *music;
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
}

void afficher_background(background *b,SDL_Surface *screen)
{SDL_BlitSurface(b->image,&b->pos,screen,NULL);
 SDL_Flip(screen);
}
