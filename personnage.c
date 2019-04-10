#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personnages.h"
#include <SDL/SDL_mixer.h>

hero Inithero(hero p,int x, int y)
{
p.image[0]=IMG_Load("1.png");
p.image[1]=IMG_Load("2.png");
p.image[2]=IMG_Load("3.png");
p.image[3]=IMG_Load("4.png");
p.image[4]=IMG_Load("5.png");
p.image[5]=IMG_Load("6.png");
p.image[6]=IMG_Load("7.png");
p.image[7]=IMG_Load("8.png");
  p.Hit=IMG_Load("9.png");
  p.imageActuelle=p.image[0];
  p.position.x=x;
  p.position.y=y;
  p.positionO=p.position;
  p.fram=0;
  p.direction=0;
  return p;
}
void  Afficherhero(hero p ,SDL_Surface *screen)
{
  SDL_BlitSurface(p.imageActuelle,NULL,screen,&p.position);
}

void clean(hero p,SDL_Surface screen)
{SDL_FreeSurface(p);
SDL_FreeSurface(screen);
}
