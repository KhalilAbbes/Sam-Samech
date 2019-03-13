#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
SDL_Surface tab[40];
Mix_Chunk *son;
SDL_Rect pos;
}person;

void initialiser_personnage(person *p,char m1[],char m2[],int nb);
void afficher_personnage(person *p,SDL_Surface *screen,int i);
void clean(SDL_Surface perso,SDL_Surface screen);




