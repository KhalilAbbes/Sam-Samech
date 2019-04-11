#include <stdio.h>
#include "SDL/SDL.h"
#include "objet.h"
#include"SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>


int main (int argc, char *argv[])
{
SDL_Surface *screen= NULL ;
SDL_Surface *image=  NULL ;
SDL_Surface *image2= NULL;
SDL_Surface *image3= NULL;

SDL_Event event;
Mix_Music *mix;


int done =1;
SDL_Rect positionecran,positionecran2,positionecran3;
int back_x=0;
int back_y=0;
int per_x=110;
int per_y=30;
int ban_x=150;
int ban_y=30 ;
	
char pause ;
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
mix=Mix_LoadMUS("music.mp3");

if (SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL: %s \n ",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(500,250, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL){
printf("unable to set video mode : %s \n",SDL_GetError());
return 1;
}
image=IMG_Load ("maison.png");
if(image==NULL){
printf("unable to load bitmap : %s \n",SDL_GetError());
return 1;
}
image2=IMG_Load("Money.png");

if(image2==NULL){
printf("unable to load bitamp : %s \n ",SDL_GetError());
SDL_SetColorKey(image2, SDL_SRCCOLORKEY, SDL_MapRGB(image2->format,255,255,255));
return 1;
}
image3=IMG_Load("515.png");
  
if(image3==NULL){
printf("unable to load bitamp : %s \n ",SDL_GetError());
SDL_SetColorKey(image3, SDL_SRCCOLORKEY, SDL_MapRGB(image3->format,255,255,255));
return 1;
}
	while (done)
{
	positionecran.x =0;
	positionecran.y =0;
	positionecran2.x=per_x;
	positionecran2.y=per_y ;
	positionecran3.x=ban_x ;
        positionecran3.y=ban_y ;


 	SDL_BlitSurface(image,NULL,screen,&positionecran);
	SDL_BlitSurface(image2,NULL,screen,&positionecran2);
        SDL_BlitSurface(image3,NULL,screen,&positionecran3);
	

SDL_Flip(screen);
}

SDL_FreeSurface(image);
SDL_FreeSurface(image2);
SDL_FreeSurface(image3);
Mix_FreeMusic(mix);
 
SDL_Quit();

return 0;
}



