
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personnages.h"

void initialiser_personnage(person *p,char m1[],char m2[],int nb)
{

int i;
for(i=0;i<nb;i++)
{	p->tab[i]=IMG_Load(m);
	if (perso==NULL)
		{printf("Error Loading person");
        	 return 1;}
}


p->pos.x=300;
p->pos.y=400;
p->pos.w=NULL;
p->pos.h=NULL;
 
p->son=Load_Chunk(m2);
}

void afficher_personnage(person *p,SDL_Surface *screen,int i)
{
SDL_BlitSurface(p->img[i],&(p->pos),screen,NULL);
SDL_Flip(screen);


}

void clean(SDL_Surface perso,SDL_Surface screen)
{SDL_FreeSurface(perso);
SDL_FreeSurface(screen);
}
