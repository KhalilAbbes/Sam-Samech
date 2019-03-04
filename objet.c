#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<string.h>
#include<objet.h>

void initialiser_objet(objet *scores,char m1[],char m2[])
{	
	if( TTF_Init() != 0 )  
		{printf("hello world");} 	
	SDL_Color Color={252,162,3};
	o->x=0;
	char text[]=o->x;
	font=TTF_OpenFont(m1,40);
	if(font==NULL) 
		{return -1;}
	scores->score=TTF_RenderText_Solid(font,text,Color); 
	scores->position.x=700;
	scores->position.y=0;
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		{printf("%s",Mix_GetError());}
	scores->son=Mix_LoadWAV(m2);
}

void afficher_objet(objet *scores,SDL_Surface *screen)
{	
	blitsurface(scores->score,&(scores->sposition),screen,NULL);

}
	
