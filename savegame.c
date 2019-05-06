#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <SDL/SDL_ttf.h>
#include "savegame.h"
#include "personnage.h"

void sauvegarder_stage (hero *p, int *stage,background *b)
{
	int a=1;
	FILE *f;

	f=fopen("savings.txt", "wb");

	fwrite(p, sizeof(hero),1,f);
	fwrite(stage, sizeof(int),1,f);
	fwrite(b,sizeof(background),1,f);

	fclose(f);

	FILE* fichier = NULL;

    fichier = fopen("saves.txt", "w");



    if (f!= NULL)

    {
            fprintf(f,"%d",a );

        fclose(f);

    }

}

void load_game (hero *p, int *stage , background *b)
{

	FILE *f=fopen("savings.txt","rb");

	if(f==NULL)
	{
	     printf("Erreur !");
	}


	else
	{
		//printf("loading");
		fread(p, sizeof(hero), 1, f);
		fread(stage, sizeof(int), 1, f);
		fread(b, sizeof(background), 1, f);
	}

	fclose(f);
}
