#include "deplacement.h"


void affi(ENTITE_SECONDAIRE *entite ,SDL_Surface *ecran)
{  
SDL_Delay(20);
SDL_BlitSurface( entite->enemis[0],NULL, ecran,&entite->position);


}
