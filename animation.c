#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "personnages.h"

person AnimatePlayer(person Hero,int direction,int Hit)
{
  if(Hero.fram==4)
  {
    Hero.fram=0;
  }
  else
  {
    Hero.fram++;
  }

  Hero.imageActuelle=Hero.tab[Hit][Hero.fram];
  return Hero;
}
