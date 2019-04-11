#ifndef DEPLACEMENT_H

#define DEPLACEMENT_H


#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h> 

#include <string.h>


typedef struct ENTITE_SECONDAIRE 
{ 

SDL_Surface* enemis[5];

SDL_Rect position;

int direction; //1 : a droite,  0: a gauche


}ENTITE_SECONDAIRE ;


void ennemi(ENTITE_SECONDAIRE *entite);

void deplacement( ENTITE_SECONDAIRE *e,int min,int max);

void affi(ENTITE_SECONDAIRE *entite,SDL_Surface *ecran);


//void pause();

//
void affi(ENTITE_SECONDAIRE *entite,SDL_Surface *ecran);

#endif

