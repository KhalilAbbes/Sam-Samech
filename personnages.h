#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{SDL_Surface tab[40];Mix_Chunk *son;Sdl_Rect pos;}person;

void initialiser_personnage(SDL_Surface *perso,SDL_Rect *positionperso);
void afficher_personnage(SDL_Surface *perso,SDL_Surface *screen);
void clean(SDL_Surface perso,SDL_Surface screen);


