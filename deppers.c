
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "deppers.h"

int main(void)
{
hero h;
h=Inithero(p,x,y);
Afficherhero(p,&screen);
SDL_Rect positionpers;

SDL_Event event;

int done = 0;
int direction=0;
while(!done)
{


switch(event.type)

{

case SDL_QUIT:
 done=0;

break;

case SDL_KEYDOWN :

switch(event.key.keysym.sym)

{

case SDLK_UP :
positionperso.y -=20;
direction=1;
break;

case SDLK_DOWN :
positionperso.y +=20;
direction=2;
break;

case SDLK_RIGHT :
positionperso.x +=20;
direction=3;
break;

case SDLK_LEFT :
positionperso.x -=20;
direction=4;
break;

default :
break;
}

switch(direction)
{ 
case 1:
hero->surf=IMG_Load("1.png");
break;
case 2:
hero->surf=IMG_Load("2.png");
break;
case 3:
hero->surf=IMG_Load("3.png");
break;
case 4:
hero->surf=IMG_Load("4.png");
break;
}

case SDL_MOUSEMOTION :
ppositionperso.x=event.motion.x;

positionperso.y=event.motion.y;

break;


default:
break;
}
}
}
return 0;
}

