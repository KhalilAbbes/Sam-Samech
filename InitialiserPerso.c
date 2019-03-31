#include "player.h"
Player InitPlayer(Player Hero)
{
  Hero.image[0][0]=IMG_Load("");
  Hero.image[0][1]=IMG_Load("");
  Hero.image[0][2]=IMG_Load("");
  Hero.image[0][3]=IMG_Load("");
  Hero.image[0][4]=IMG_Load("");
  Hero.image[1][0]=IMG_Load("");
  Hero.image[1][1]=IMG_Load("");
  Hero.image[1][2]=IMG_Load("");
  Hero.image[1][3]=IMG_Load("");
  Hero.image[1][4]=IMG_Load("");
  Hero.imageActuel=Hero.image[0][0];
  Hero.position.x=450;
  Hero.position.y=342- Hero.imageActuel->h;
  Hero.frame=0;
  Hero.vie.image=IMG_Load("coeur.png");
  Hero.score=0;
  Hero.vie.nbr=3;

  Hero.vie.position.x=20;
  Hero.vie.position.y=20;
  return Hero;
}


void AfficherPlayer(Player Hero , SDL_Surface *screen)
{
  SDL_BlitSurface(Hero.imageActuel,NULL,screen,&Hero.position);
}


Player AnimatePlayer(Player Hero,int direction,int Hit)
{
  if(Hero.frame==4)
  {
    Hero.frame=0;
  }
  else
  {
    Hero.frame++;
  }

  Hero.imageActuel=Hero.image[Hit][Hero.frame];
  return Hero;
}


Player MovePlayer(Player Hero,int direction,int x)
{
  if(direction==0)
  {printf("%d    %d\n",x,Hero.position.x );

    if((Hero.position.x<450))
      Hero.position.x+=20;
    else if((x>6000)&&(Hero.position.x<920))
      Hero.position.x+=20;
  }
  else if(direction==1)
  {
    if((x==0)&&(Hero.position.x>0))
      Hero.position.x-=20;
    else if(Hero.position.x>450)
      Hero.position.x-=20;
  }
  if(direction==2)
    Hero.position.y-=20;
  /*else if(direction==3)
    Hero.position.y+=20;*/
  return Hero;
}


void gestion_vie(vie *v,int i)
{
  if(i==1)
   v->nbr--;
}

void gestion_score (score s , int i)
{
  if (i==1)
  s->nb=nb+10;
}

void  afficher_vie(vie v,SDL_Surface *screen)
{
  int i;
  SDL_Rect position;
  for(i=0;i<v.nbr;i++)
  {
    position.x=v.position.x+(v.image->w*i);
    position.y=20;
    SDL_BlitSurface(v.image,NULL,screen,&position);
  }

void afficher_score(score s , SDL_Surface *screen, int i)
{
  int j,k=0 ;
  SDL_Rect pos;
  for (j=0;j<999;j++)
  { 
  pos.x=600;
  pos.y=20;
  if (i==1)
  {
  SDL_BlitSurface(s.image[k],NULL,screen,&pos);
  k++;
  }
  }



