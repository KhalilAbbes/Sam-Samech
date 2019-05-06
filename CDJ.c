#include "jeux.h"

void gagner(SDL_Surface *ecran, personnage *p, background *b,temps *temp)
{
	
	
	SDL_Event event;
	SDL_Surface *rectangle;
	SDL_Rect position;
	SDL_Surface *texte;
	SDL_Color couleur={0,0,0};
	SDL_Rect position_texte;
	TTF_Font *police=NULL;
	position.x=0;
	position.y=0;
	position_texte.x=200;
	position_texte.y=500;
	TTF_Init();
        police=TTF_OpenFont("font/transformers.ttf",100);
	rectangle=SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 1000, 32, 0, 0, 0, 0);
	SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format, 255,255,255));  
	texte=TTF_RenderText_Solid(police,"YOU WIN",couleur);
	if ((p.temps!=0)&&(p.nombre_vie!=0)&&(p.stage==4))
{
	
	SDL_BlitSurface(rectangle,NULL,ecran,&position);
	SDL_BlitSurface(texte,NULL,ecran,&position_texte);
	SDL_Flip(ecran);
}
 TTF_CloseFont(police);
 TTF_Quit();
}



void perdu(SDL_Surface *ecran , personnage *p , background *b)
{

	SDL_Event event;
	SDL_Surface *rectangle;
	SDL_Rect position;
        SDL_Surface *texte;
        SDL_Color couleur={0,0,0};
        SDL_Rect position_texte;
        TTF_Font *police=NULL;
        position.x=0;
        position.y=0;
        position_texte.x=200;
        position_texte.y=500;
        TTF_Init();
        police=TTF_OpenFont("font/transformers.ttf",100);
        rectangle=SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 1000, 32, 0, 0, 0, 0$
        SDL_FillRect(rectangle,NULL,SDL_MapRGB(ecran->format, 255,255,255));  
        texte=TTF_RenderText_Solid(police,"YOU LOSE",couleur);
        if ((p.temps==0)||(p.nombre_vie==0))
{

        SDL_BlitSurface(rectangle,NULL,ecran,&position);
        SDL_BlitSurface(texte,NULL,ecran,&position_texte);
        SDL_Flip(ecran);
}
 TTF_CloseFont(police);
 TTF_Quit();
}


