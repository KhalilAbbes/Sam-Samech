#ifndef BACKGROUND_H_
#define BACKGROUND_H_
typedef struct{SDL_Surface *image ;SDL_Rect pos;}background;
int initialiser_background(background *b, char m[], SDL_Surface *screen);
void clean_background(background *b,SDL_Surface *screen);
#endif /*BACKGROUND_H_*/
