#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>



int main(int argc, char **argv)

{
    int r=0;
    srand(time(NULL));

    FILE* fichier1=NULL,*fichier2=NULL,*fichier3=NULL,*fichier4=NULL,*fichier5=NULL,*solution=NULL;
    r=rand()%4;


    char chaine1[256]="",chaine2[256]="",chaine3[256]="",chaine4[256]="",chaine5[256]="",chaines,ch;





    switch(r)
    {

    case 1 :
        fichier1=fopen("e11.txt", "r");
        fichier2=fopen("e12.txt", "r");
        fichier3=fopen("e13.txt", "r");
        fichier4=fopen("rep1.txt", "r");
        fichier5=fopen("rep12.txt", "r");
        solution=fopen("solution1.txt","r");
        break;
    case 2 :
        fichier1=fopen("e21.txt", "r");
        fichier2=fopen("e22.txt", "r");
        fichier3=fopen("e23.txt", "r");
        fichier4=fopen("rep2.txt", "r");
        fichier5=fopen("rep22.txt", "r");
        solution=fopen("solution2.txt","r");
        break;
    case 3 :
        fichier1=fopen("e31.txt", "r");
        fichier2=fopen("e32.txt", "r");
        fichier3=fopen("e33.txt", "r");
        fichier4=fopen("rep3.txt", "r");
        fichier5=fopen("rep32.txt", "r");
        solution=fopen("solution3.txt","r");
        break;
    case 4 :
        fichier1=fopen("e41.txt", "r");
        fichier2=fopen("e42.txt", "r");
        fichier3=fopen("e43.txt", "r");
        fichier4=fopen("rep4.txt", "r");
        fichier5=fopen("rep42.txt", "r");
        solution=fopen("solution4.txt","r");
        break;
    case 0 :
        fichier1=fopen("e11.txt", "r");
        fichier2=fopen("e12.txt", "r");
        fichier3=fopen("e13.txt", "r");
        fichier4=fopen("rep1.txt", "r");
        fichier5=fopen("rep12.txt", "r");
        solution=fopen("solution1.txt","r");
        break;
    }

    if(fichier1!=NULL)
    {

        fgets (chaine1, 265, fichier1 );
        fclose(fichier1);

    }
    if(fichier2!=NULL)
    {

        fgets (chaine2, 265, fichier2 );
        fclose(fichier2);

    }
    if(fichier3!=NULL)
    {

        fgets (chaine3, 265, fichier3 );
        fclose(fichier3);

    }
    if(fichier4!=NULL)
    {

        fgets (chaine4, 265, fichier4 );
        fclose(fichier4);

    }
    if(fichier5!=NULL)
    {

        fgets (chaine5, 265, fichier5 );
        fclose(fichier5);

    }


   do
		
{
		
	chaines=fgetc(solution);	
		
}while(chaines!=EOF);

    SDL_Surface *ecran = NULL, *texte1= NULL,*texte2 = NULL,*texte3 = NULL,*texte4 = NULL,*texte5 = NULL, *fond = NULL;
    SDL_Rect positiontexte1,positiontexte2,positiontexte3,positiontexte4,positiontexte5, positionfond;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};

    int continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    ecran = SDL_SetVideoMode(713, 403, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("GENERATION ALEATOIRE DE L ENIGME", NULL);


    fond = IMG_Load("enigme.png");
    police = TTF_OpenFont("Candyshop.ttf", 23);



    texte1 = TTF_RenderText_Blended(police,chaine1, couleurNoire);
    texte2 = TTF_RenderText_Blended(police,chaine2, couleurNoire);
    texte3 = TTF_RenderText_Blended(police,chaine3, couleurNoire);
    texte4 = TTF_RenderText_Blended(police,chaine4, couleurNoire);
    texte5 = TTF_RenderText_Blended(police,chaine5, couleurNoire);

    positionfond.x = 0;

    positionfond.y = 0;


    SDL_BlitSurface(fond, NULL, ecran, &positionfond);
    SDL_SetColorKey(fond, SDL_SRCCOLORKEY, SDL_MapRGB(fond->format, 0, 0, 0));


    positiontexte1.x = 90;

    positiontexte1.y = 170;
    positiontexte2.x = 90;

    positiontexte2.y = 200;
    positiontexte3.x = 90;

    positiontexte3.y = 230;
    positiontexte4.x = 420;

    positiontexte4.y = 230;
    positiontexte5.x = 420;

    positiontexte5.y = 250;



    SDL_BlitSurface(texte1, NULL, ecran, &positiontexte1);
    SDL_BlitSurface(texte2, NULL, ecran, &positiontexte2);
    SDL_BlitSurface(texte3, NULL, ecran, &positiontexte3);
    SDL_BlitSurface(texte4, NULL, ecran, &positiontexte4);
    SDL_BlitSurface(texte5, NULL, ecran, &positiontexte5);

    SDL_Flip(ecran);


    while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)


        {
        case SDL_QUIT:

            continuer = 0;

            break;

        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)

            {

            case SDLK_a:

                ch='a';

                break;

            case SDLK_b:


                ch='b';


                break;

            case SDLK_c:

                ch='c';

                break;

            case SDLK_d:


                ch='d';

                break;


            }

        }
    }
    SDL_Surface *echec=NULL,*vrai=NULL;
    SDL_Rect positionimage;
    vrai=IMG_Load("win.png");

    echec=IMG_Load("lost.png");
    positionimage.x=0;

    positionimage.y=0;
    if(ch==chaines)
    {


        SDL_BlitSurface(vrai,NULL,ecran,&positionimage);
        SDL_Flip(ecran);
    }
SDL_Flip(ecran);
    if(ch!=chaines)
    {


        SDL_BlitSurface(echec,NULL,ecran,&positionimage);
        SDL_Flip(ecran);

    }
SDL_Flip(ecran);
    TTF_CloseFont(police);

    TTF_Quit();
    SDL_FreeSurface(texte1);
    SDL_FreeSurface(texte2);
    SDL_FreeSurface(texte3);
    SDL_FreeSurface(texte4);
    SDL_FreeSurface(texte5);



    SDL_Quit();


    return (EXIT_SUCCESS);

}

