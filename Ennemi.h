#ifndef INITIALISATIONENNEMI_H_INCLUDED
#define INITIALISATIONENNEMI_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

typedef struct
{
    SDL_Rect pos ;
    Mix_music interagir ;
    SDL_Event event ;
    SDL_Surface *image ;
}InitEnnemi;

Initialier_ennemi (InitEnnemi e,SDL_Surface &screen);
Afficher_Ennemi (InitEnnemi e,SDL_Surface &screen );
#endif // INITIALISATIONENNEMI_H_INCLUDED
