#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct{Sdl_surface *image;Sdl_Rect pos;Mix_Music *son;}background;
void initialiser_background(background *b);
void clean_background(background *b,SDL_Surface *screen);
