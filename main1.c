#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>
#include "deplacement.h"
void main()
{  int done=1,min=0, max = 400;
 ENTITE_SECONDAIRE entite;
  SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran=NULL;
SDL_Surface *imageFOND=NULL;
SDL_Rect positionFond;


      positionFond.x=0;
      positionFond.y=0;

	ecran=SDL_SetVideoMode(700,430,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("MECHMECHA",NULL);
//imageFOND=SDL_LoadBMP("niveau1.bmp");
ennemi(&entite);







while(done==1)
{
SDL_PollEvent(&event);
SDL_BlitSurface(imageFOND,NULL, ecran ,&positionFond);
deplacement(&entite,min,max);
affi(&entite,ecran);
SDL_Flip(ecran);
//SDL_WaitEvent(&event);
 switch(event.type)
        { 
            case SDL_QUIT:
                done= 0;
                break;
            case SDL_KEYDOWN :
  switch(event.key.keysym.sym)
        {
     case SDLK_ESCAPE :
      done = 0;
      break;
       }
        }

}
SDL_FreeSurface(entite.enemis[0]);
SDL_FreeSurface(imageFOND);
SDL_FreeSurface(ecran);		
SDL_Quit();
}

/*pause();*/
     /* Mise à jour de l'écran avec sa nouvelle couleur */

//SDL_WM_SetCaption("THE PURSUIT OF GOLEMS",NULL);




 
   //SDL_WaitEvent(&event);

 //intialiser_entite(entite);
 //afficherennemi(entite,ecran);
//SDL_Flip(ecran);
 
// afficherentite(entite,ecran);
//******************************************************
/*int a =1;
SDL_Event eventx;
while(a)
{
 SDL_WaitEvent(&eventx);
 switch(eventx.type)
 {
  case SDL_KEYDOWN :
  switch(eventx.key.keysym.sym)
   {
     case SDLK_ESCAPE :
      a = 0;
      break;
   }
  }
}*/



