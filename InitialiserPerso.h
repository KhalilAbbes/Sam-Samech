#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct 
{
  int nbr;
  SDL_Rect pos;
  SDL_Surface *image;
}vie;

typedef struct 
{
   int nb;
   SDL_Rect pos;
   SDL_Surface *image[10];
}score;


typedef struct 
{
  SDL_Surface *image[2][5];
  SDL_Surface *imageActuel;
  int frame;
  SDL_Rect position;
  score score;
  vie vie;
}Player;

void gestion_score(score *s,int i);
void afficher_score(score *s , SDL_Surface *screen);
Player InitPlayer(Player Hero);
void AfficherPlayer(Player Hero,SDL_Surface *screen);
Player AnimatePlayer(Player Hero,int direction,int Hit);
Player MovePlayer(Player Hero,int direction,int x);
void  afficher_vie(vie v,SDL_Surface *screen);
void gestion_vie(vie *v,int i);

