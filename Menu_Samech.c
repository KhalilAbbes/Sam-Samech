#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include<string.h>

typedef struct {SDL_Surface *img; Mix_Music *musique;}backgrounds;
typedef struct {SDL_Surface *message;char texte[10]; SDL_Rect position; Mix_Chunk *click;}boutons;

int main()
{
	//initialisation
	SDL_Surface *screen=NULL;
	SDL_Surface *clown=NULL;
	backgrounds background;
	SDL_Rect positionecrans;
	boutons b[4];
	TTF_Font *font;
	int quit=0;
	SDL_Event event;
	int k=0;
	SDL_Color Color1={253,204,99};
	SDL_Color Color2={252,162,3};
	background.img=NULL;
	
	
	
	if (SDL_Init(SDL_INIT_VIDEO)!=0)
		{printf("Unable t initialize SDL: %s\n",SDL_GetError());
		 return -1;}
	screen=SDL_SetVideoMode(800,600,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen==NULL)
		{printf("Unable to set 800x600 video: %s\n",SDL_GetError());
		 return -1;}
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		{printf("%s",Mix_GetError());}
	if( TTF_Init() != 0 )  
		{printf("hello world");} 

	//Load files
	SDL_WM_SetCaption( "Samech", NULL ); 
	background.img=IMG_Load("menu1.jpg");
	if(background.img==NULL) 
		{return -1;} 
	clown=IMG_Load("clown01.png");
	if(clown==NULL) 
		{return -1;} 
	font=TTF_OpenFont("Robot Crush Italic.ttf",40);
	if(font==NULL) 
		{return -1;}
	background.musique=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(background.musique,-1);
	b[0].click=Mix_LoadWAV("Mousclik.wav");
	//b[1].click=Mix_LoadMUS("ButtonClick.mp3");
	//b[2].click=Mix_LoadMUS("ButtonClick.mp3");
	//b[3].click=Mix_LoadMUS("ButtonClick.mp3");
	
	char texte0[]="Play";
	char texte1[]="Options";
	char texte2[]="Scores";
	char texte3[]="Credits";

	b[0].position.x=100;
	b[0].position.y=250;
	b[1].position.x=100;
	b[1].position.y=400;
	b[2].position.x=555;
	b[2].position.y=250;
	b[3].position.x=555;
	b[3].position.y=400;

	

	b[0].message=TTF_RenderText_Solid(font,texte0,Color1); 
	b[1].message=TTF_RenderText_Solid(font,texte1,Color1);
	b[2].message=TTF_RenderText_Solid(font,texte2,Color1);
	b[3].message=TTF_RenderText_Solid(font,texte3,Color1);
	positionecrans.x=0;
	positionecrans.y=0;
	positionecrans.w=background.img->w;
	positionecrans.h=background.img->h;
	
	SDL_BlitSurface(background.img,NULL,screen,NULL);
	SDL_BlitSurface(clown,NULL,screen,NULL);
	

	

	while(quit==0)
		{
		 


		while(SDL_PollEvent(&event))
			{switch(event.type)
				{case SDL_QUIT: quit=1;break;
				 case SDL_KEYDOWN:switch(event.key.keysym.sym)
					{case SDLK_UP:Mix_PlayChannel( -1,b[0].click, 0 );k--;if(k<0){k=3;}break;
					 case SDLK_DOWN:Mix_PlayChannel( -1,b[0].click, 0 );k++;if(k>3){k=0;}break;}break;
				 }}
		switch(k)
			{case 0:
			 b[0].message=TTF_RenderText_Solid(font,texte0,Color2); 
		 	 SDL_BlitSurface(b[0].message,NULL,screen,&(b[0].position));
			 b[1].message=TTF_RenderText_Solid(font,texte1,Color1);			 
			 SDL_BlitSurface(b[1].message,NULL,screen,&(b[1].position));
			 b[2].message=TTF_RenderText_Solid(font,texte2,Color1);			 
			 SDL_BlitSurface(b[2].message,NULL,screen,&(b[2].position));
			 b[3].message=TTF_RenderText_Solid(font,texte3,Color1);			 
			 SDL_BlitSurface(b[3].message,NULL,screen,&(b[3].position));
			 break;
		
	 		 case 1:
			 b[1].message=TTF_RenderText_Solid(font,texte1,Color2); 
		 	 SDL_BlitSurface(b[1].message,NULL,screen,&(b[1].position));
			 b[0].message=TTF_RenderText_Solid(font,texte0,Color1);			 
			 SDL_BlitSurface(b[0].message,NULL,screen,&(b[0].position));
			 b[2].message=TTF_RenderText_Solid(font,texte2,Color1);			 
			 SDL_BlitSurface(b[2].message,NULL,screen,&(b[2].position));
			 b[3].message=TTF_RenderText_Solid(font,texte3,Color1);			 
			 SDL_BlitSurface(b[3].message,NULL,screen,&(b[3].position));
			 break;
	
	 		 case 2:
			 b[2].message=TTF_RenderText_Solid(font,texte2,Color2); 
		 	 SDL_BlitSurface(b[2].message,NULL,screen,&(b[2].position));
			 b[1].message=TTF_RenderText_Solid(font,texte1,Color1);			 
			 SDL_BlitSurface(b[1].message,NULL,screen,&(b[1].position));
			 b[0].message=TTF_RenderText_Solid(font,texte0,Color1);			 
			 SDL_BlitSurface(b[0].message,NULL,screen,&(b[0].position));
			 b[3].message=TTF_RenderText_Solid(font,texte3,Color1);			 
			 SDL_BlitSurface(b[3].message,NULL,screen,&(b[3].position));
			 break;

	 		 case 3:
			 b[3].message=TTF_RenderText_Solid(font,texte3,Color2); 
		 	 SDL_BlitSurface(b[3].message,NULL,screen,&(b[3].position));
			 b[1].message=TTF_RenderText_Solid(font,texte1,Color1);			 
			 SDL_BlitSurface(b[1].message,NULL,screen,&(b[1].position));
			 b[2].message=TTF_RenderText_Solid(font,texte2,Color1);			 
			 SDL_BlitSurface(b[2].message,NULL,screen,&(b[2].position));
			 b[0].message=TTF_RenderText_Solid(font,texte0,Color1);			 
			 SDL_BlitSurface(b[0].message,NULL,screen,&(b[0].position));


			 break;
			}
			 SDL_FreeSurface(screen);	
			 SDL_Flip(screen);
		}
SDL_VideoQuit();
SDL_Quit ();
}

	

	
	
	

	



