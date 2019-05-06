
#include "jeux.h"


void scrolling (hero *p , SDL_Surface *ecran)
{

if (p->buttoncameraright)
{


	p->camera.x+=p->speed_camera;
	if (p->camera.x>=8773-800)
	{
		p->camera.x=0;
	}
	
	
}

if (p->buttoncameraleft)
{


	p->camera.x-=p->speed_camera;
	if (p->camera.x>8773-800)
	{
		p->camera.x=0;
	}
} 

