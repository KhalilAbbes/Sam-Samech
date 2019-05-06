/**
* @file affenigme.h
* @brief fonction.h
* @author k ghenimi
* @version 0.1
* @date 05 mai, 2019
*
* @struct enigme
* @brief struct for enigme
*
*/
#ifndef AFFENIGME_H_INCLUDED
#define AFFENIGME_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct aff_eng
{
    SDL_Surface* enig[4] ; /*!< image la surface*/ 
    SDL_Rect posenig ;  /*!< Rectangle*/ 
} aff_eng;

int afficher_enigme (aff_eng enig );
int resol_enigme (aff_eng enig , int colusion );
void pause();

#endif
