#include "deplacement.h"

void ennemi(ENTITE_SECONDAIRE *entite)
{ 
entite->enemis[0]=IMG_Load("mech.png");
if(entite->enemis[0]==NULL)
		exit(EXIT_FAILURE);

entite->position.x=0;
entite->position.y=0;
entite->direction =1;



}


