#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
typedef struct 
{

SDL_Rect position;
SDL_Surface *surface;
}entite;

SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	char* pPosition = ( char* ) surface->pixels ;

	pPosition += ( surface->pitch * y ) ;

	pPosition += ( surface->format->BytesPerPixel * x ) ;


	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;


	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collision_Parfaite(SDL_Surface *calque, SDL_Surface *perso,SDL_Rect posperso,int decalage,int d)
{

  SDL_Color col;
  if(d==0)
  {
    col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));
  }
else  if(d==1)
  {
    col=GetPixel(calque,posperso.x +decalage,posperso.y+(perso->h/2));
  }
else  if(d==2)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2)+decalage ,posperso.y);
  }
else  if(d==3)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) +decalage,posperso.y+perso->h);
  }
 
if ((col.r==255)&&(col.g==255)&&(col.b==255))
{
  return 1;
}
else return 0;
}
int main ()
{
int a;
entite e1,e2;
SDL_Surface *ecran=NULL;

SDL_Init(SDL_INIT_VIDEO);
ecran = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);

e1.surface = SDL_LoadBMP("background.bmp");
e2.surface = IMG_Load("backgroundmasque.png");

e1.position.x = 100;
e1.position.y = 100;

e2.position.x = 100;
e2.position.y = 0;

while(1){
SDL_BlitSurface(e1.surface,NULL,ecran,&e1.position);
SDL_BlitSurface(e2.surface,NULL,ecran,&e2.position);
SDL_Flip(ecran);
a=collision_Parfaite(&calque, &perso,posperso, decalage, d)
printf("%d\n",a);
}

return 0;
}




