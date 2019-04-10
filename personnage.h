#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_
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

hero Inithero(hero p,int x, int y);
void  Afficherhero(hero p ,SDL_Surface *screen);
void clean(hero p,SDL_Surface screen);
#endif /*PERSONNAGE_H_*/
