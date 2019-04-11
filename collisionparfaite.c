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

typedef struct hero
{
  SDL_Surface *image[8];
  SDL_Surface *Hit;
  SDL_Surface *imageActuelle;
  SDL_Rect position;
  SDL_Rect positionO;
  int fram;
  int direction;

}hero;

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

int collision_Parfaite(SDL_Surface *calque, SDL_Surface *perso,SDL_Rect posperso,int d)
{

  SDL_Color col;
  if(d==0)
  {
    col=GetPixel(calque,posperso.x+perso->w ,posperso.y+(perso->h/2));
  }
else  if(d==1)
  {
    col=GetPixel(calque,posperso.x ,posperso.y+(perso->h/2));
  }
else  if(d==2)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2),posperso.y);
  }
else  if(d==3)
  {
    col=GetPixel(calque,posperso.x+(perso->w/2) ,posperso.y+perso->h);
  }
 
if ((col.r==0)&&(col.g==0)&&(col.b==0))
{
  return 1;
}
return 0;
}

hero Movehero(hero p ,SDL_Rect personnage,int *stat)
{

int distance;

  if(p.position.x>=personnage.x)
    distance=p.position.x-personnage.x;
  else
    distance=personnage.x-p.position.x;
if(distance<50)*stat=1;
else *stat=0;
    if(distance<200)
      {
        if(p.position.x>=personnage.x)
          p.direction=0;
        else
          p.direction=1;
      }

      else
    {  if(p.positionO.x+100==p.position.x)
          p.direction=0;

      if(p.positionO.x-100==p.position.x)

        p.direction=1;}


      if(p.direction==1)
      {
        p.position.x+=5;
      }
      if(p.direction==0)
      {
        p.position.x-=5;
      }


  return p;
}

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

hero Animatehero(hero p)
{
  if (p.fram>7) {
    p.fram=0;
  }
  else
 p.fram++;
  p.imageActuelle=p.image[p.fram];
  return p;
}



int main ()
{
int a;
hero p;
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
SDL_Surface *ecran;
  SDL_Surface *personnage =NULL;
   SDL_Init(SDL_INIT_VIDEO);
   hero h;
h=Inithero(h,0,250);
ecran = SDL_SetVideoMode(800, 600,32,SDL_HWSURFACE || SDL_DOUBLEBUF||SDL_FULLSCREEN );
	SDL_Rect pos;

pos.y=250;
pos.x=0;

    SDL_Event event;
    int continuer = 1,a;





    while (continuer)
    { SDL_PollEvent(&event);


      
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
		case SDL_KEYUP:
break;
            case SDL_KEYDOWN :

                 switch(event.key.keysym.sym)
                {


                    case SDLK_RIGHT:

if(collision_Parfaite(e2.surface,h.image[0],h.position,0))
	h.position.x-=30;
h.position.x+=30;

                        break;
                    case SDLK_LEFT :

if(collision_Parfaite(e2.surface,h.image[0],h.position,1))
	h.position.x+=30;

h.position.x-=30;

                    break;




                }

        }
SDL_Delay(90);

h=Movehero(h,pos,&a);
h=Animatehero(h);
 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
  Afficherhero(h,ecran);
        SDL_Flip(ecran);
SDL_BlitSurface(e1.surface,NULL,ecran,&e1.position);
SDL_BlitSurface(e2.surface,NULL,ecran,&e2.position);

 SDL_BlitSurface(personnage,NULL,ecran, &pos);
SDL_Flip(ecran);

}

return 0;
}
}




