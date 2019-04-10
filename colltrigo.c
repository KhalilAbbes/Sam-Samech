#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include "colltrigo.h"

int collision_trigo (SDL_Rect rect1 , SDL_Rect rect2)
{
   float X1,Y1,R1,X2,Y2,R2,x1=rect1.x,y1=rect1.y,x2=rect2.x,y2=rect2.y,
w1,h1,w2,h2,D1,D2;
   int verif=0;

X1=x1+(w1/2);
Y1=y1+(h1/2);
R1=sqrt((pow(h1/2,2))+(pow(w1/2,2)));

X2=x2+(w2/2);
Y2=y2+(h2/2);
R2=sqrt((pow(h2/2,2))+(pow(w2/2,2)));

D1=sqrt((pow(X1-X2,2))+(pow(Y1-Y2,2)));
D2=R1+R2;

if(D1<=D2)
   verif=1;
else
   verif=0;
return verif;
}
