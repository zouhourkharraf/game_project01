#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>



typedef struct
{
SDL_Surface *spritesheet;
SDL_Rect posennemi;
SDL_Rect possprite;
int direction;
}Ennemi;


//la structure personne
typedef struct
{
SDL_Surface *sprite_perso;
SDL_Rect posperso;
SDL_Rect possprite_perso;
int direction_perso;
}personne;


void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e);
//void deplacerIA( Ennemi * e);


// les fonction associées au personnage
void init_personnage(personne* p);
void afficher_personnage(personne p, SDL_Surface * screen);  
