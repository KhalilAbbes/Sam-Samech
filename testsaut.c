/**
* @file testsaut.c
* @brief Testing Program.
* @author maryem bessrour
* @version 0.1
* @date may 05, 2019
*
*
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

 
int main ()
{
    int tempsPrecedent = 0, tempsActuel = 0,t=0;
    
    SDL_Init( SDL_INIT_VIDEO );
    SDL_Event event1;
    
    SDL_Surface* ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
 
    
    SDL_Surface* fond = SDL_LoadBMP("background.bmp");
 
    
    SDL_Surface *pers = IMG_Load("1.png");
 
    
    SDL_Rect posFond;
    posFond.x = 0;
    posFond.y = 0;
 
    
    SDL_Rect pospers;
    pospers.x = 100;
    pospers.y = 300-(pers->h);
 
  
    double v_x = 1.5;
 
    double v_grav = 0.08;
    double v_saut = -3;
 
    double v_y = v_saut;
 
    
    int continuer = 1;
        SDL_EnableKeyRepeat(10, 10);
    while(continuer)
    {
     while( SDL_PollEvent( &event1 ) )
        {
 
                tempsActuel = SDL_GetTicks();
        switch (event1.type)
        {
                case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
            switch (event1.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
 
                case SDLK_UP:
                    if (tempsActuel - tempsPrecedent > 2) 
                    {
                        t=1;
                    pospers.x += v_x;
                    pospers.y += v_y;
                    
                    v_y += v_grav;
                        tempsPrecedent = tempsActuel;
                    }
                    
                    
 
                    
                    if(t==1)
                    {
                    if (pospers.y > 300)
                    {
                        pospers.y=300;
                        t=0;
                  
                    }
                    }
                    break;
 
 
            default:
            break;
 
            }
            break;
 
 
        }
        }
 
        SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(fond, 0, ecran, &posFond);
        SDL_BlitSurface(pers, 0, ecran, &pospers);
 
      
        SDL_Flip(ecran);
    }
 
   
    SDL_FreeSurface(fond);
    SDL_FreeSurface(pers);
 
    SDL_Quit();
 
    return 0;
}
