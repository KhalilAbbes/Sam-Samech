#include <stdio.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"

int main(int argc, char *argv[])

{
SDL_Surface *screen= NULL ;
SDL_Surface *image=  NULL ;
SDL_Surface *image2=NULL;
SDL_Event event;
int done =1;
SDL_Rect positionecran,positionecran2;
int back_x=0;
int back_y=0;
int per_x=5;
int per_y=10;
char pause ;

if (SDL_Init(SDL_INIT_VIDEO)!=0)
{

printf("unable to initialize SDL: %s \n ",SDL_GetError());

return 1;

}

screen=SDL_SetVideoMode(500,250, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);

if (screen==NULL)
{

printf("unable to set video mode : %s \n",SDL_GetError());

return 1;

}
image=IMG_Load ("maison.png");
if(image==NULL){
printf("unable to load bitmap : %s \n",SDL_GetError());
return 1;
}

image2=IMG_Load("255.png");
if(image2==NULL)
{
printf("unable to load bitamp : %s \n ",SDL_GetError());
SDL_SetColorKey(image2, SDL_SRCCOLORKEY, SDL_MapRGB(image2->format,255,255
,255));
return 1;
}

while (done)
{
	positionecran.x =0;
	positionecran.y =0;
	positionecran2.x =per_x;
	positionecran2.y =per_y;
 	SDL_BlitSurface(image, NULL , screen,   &positionecran);
	SDL_BlitSurface(image2, NULL , screen , &positionecran2);

SDL_Flip(screen);
}
SDL_FreeSurface(image);
SDL_FreeSurface(image2);
SDL_Quit();


return 0;

}
