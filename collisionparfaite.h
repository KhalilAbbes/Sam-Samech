#ifndef BACKGROUND_H_
#define BACKGROUND_H_
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int collision_Parfaite(SDL_Surface *calque, SDL_Surface *perso,SDL_Rect posperso,int d);
#endif /*BACKGROUND_H_*/

