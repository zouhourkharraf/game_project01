#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<time.h> 

#include"entite_second.h"


const int LARGEUR_SPRITE= 504;
const int HAUTEUR_SPRITE= 256;

void initEnnemi(Ennemi*e)
{
const int A=40,B=760;
srand(time(NULL));

e->spritesheet = IMG_Load("spritesheet.png"); //chargement du sprite sheet

//les posisiton de l'ennemi sur l'écran
e->posennemi.y=350;
e->posennemi.x=(rand() % (B - A + 1)) +A ;

//le clip initial
e->possprite.x=0;
e->possprite.y=0;
e->possprite.w=84;
e->possprite.h=128;

//la direction initial
e->direction=0;

}

void afficherEnnemi(Ennemi e, SDL_Surface * screen)
{

SDL_BlitSurface( e.spritesheet , &e.possprite , screen , &e.posennemi );
SDL_Flip(screen);

}

void animerEnnemi( Ennemi * e)
{

if(e->direction == 0)
   e->possprite.y= 0; 
else
   e->possprite.y= 128; 
if(e->possprite.x == LARGEUR_SPRITE -84 ) 
   e->possprite.x=0; 
else
   e->possprite.x += 84 ; 

}


void deplacer( Ennemi * e)
{
if( e->posennemi.x > 740 )
 e->direction = 1;
if( e->posennemi.x < 0 )
 e->direction = 0;

if( e->direction == 0)
  e->posennemi.x+=3;
else
  e->posennemi.x-=3;

}

int collisionBB( personne p, Ennemi e) 
{
if(( (p.posperso.x + p.possprite_perso.w)< e.posennemi.x ) || (e.posennemi.x + e.possprite.w < p.posperso.x ) )
return 0;
else
return 1;

} 

void init_personnage(personne* p)
{ 

p->sprite_perso = IMG_Load("spritepersonne.png"); 

p->posperso.x= 400;
p->posperso.y= 320;

//le clip à afficher
p->possprite_perso.x=0;
p->possprite_perso.y=0;
p->possprite_perso.w=80;
p->possprite_perso.h=160;

p->direction_perso=0;


}


void afficher_personnage(personne p, SDL_Surface * screen)
{
SDL_BlitSurface( p.sprite_perso , &p.possprite_perso , screen , &p.posperso );
SDL_Flip(screen);
}



/*
void deplacerIA( Ennemi * e)
{
}


*/

