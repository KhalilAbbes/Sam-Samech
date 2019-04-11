#include <stdio.h> 
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct {
    SDL_Surface* img[4];
    Mix_Music* m;
    int valeur; 
}coin;

void init_coin(coin* c){
    c->img[0]=IMG_Load("flous1.png");
    c->img[1]=IMG_Load("flous2.png");
    c->img[2]=IMG_Load("flous3.png");
    //c->img[3] =IMG_Load("4.png");
    c->valeur=10;
}
void main(){
 SDL_Event event;
 SDL_Init(SDL_INIT_VIDEO);
 int i=0 ;
 coin c;
 SDL_Rect pos; 
 pos.x=0;
 pos.y=0;
 SDL_Surface* bg; 
 bg=SDL_SetVideoMode(500,500,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 init_coin(&c);

while(1)
{
SDL_Delay(200);
SDL_BlitSurface(c.img[i%4],NULL,bg,&pos);
SDL_Flip(bg);
i++;
}
SDL_Quit();
}
