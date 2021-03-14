#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include"prototypes.h"


void animation(SDL_Surface *ecran)
{
SDL_Surface *texte=NULL;// initialisation de la surface du texte
SDL_Surface *image_anim1=NULL,*image_anim2=NULL,*image_anim3=NULL,*image_anim4=NULL,*image_anim5=NULL,*image_anim6=NULL;//les images pour l'animation

TTF_Font *police = NULL; //inisialisation de la police (Le pointeur qui va stocker la poclice)
SDL_Rect position;//La position du texte

SDL_Rect pos_image_anim1,pos_image_anim2,pos_image_anim3,pos_image_anim4,pos_image_anim5,pos_image_anim6;
  pos_image_anim1.x=0;
     pos_image_anim1.y=0;
     pos_image_anim2.x=0;
     pos_image_anim2.y=0;
     pos_image_anim3.x=0;
     pos_image_anim3.y=0;
     pos_image_anim4.x=0;
     pos_image_anim4.y=0;
     pos_image_anim5.x=0;
     pos_image_anim5.y=0;
     pos_image_anim6.x=0;
     pos_image_anim6.y=0;

    position.x = 600; //Postion du texte
   position.y = 500; //Postion du texte  

police = TTF_OpenFont("hellojones.ttf",22); //charger la police
SDL_Color couleurNoire = {0, 0, 0};//une variable qui stocke la couleur noire 
texte=TTF_RenderText_Blended(police,"© one piece 2021", couleurNoire); // écrire un texte en noir dans une SDL_Surface texte en mode blended

image_anim1= IMG_Load("anim1.png");
image_anim2= IMG_Load("anim2.png");
image_anim3= IMG_Load("anim3.png");
image_anim4= IMG_Load("anim4.png");
image_anim5= IMG_Load("anim5.png");
image_anim6= IMG_Load("anim6.png");
//L'aniamtion:la succession d'images

SDL_BlitSurface(image_anim1, NULL, ecran,&pos_image_anim1); 
SDL_BlitSurface(texte,NULL, ecran,&position); // Blit du texte
SDL_Flip(ecran); 
SDL_Delay(500);
SDL_BlitSurface(image_anim2, NULL, ecran,&pos_image_anim2); 
SDL_BlitSurface(texte,NULL, ecran,&position); 
SDL_Flip(ecran); 
SDL_Delay(500);
SDL_BlitSurface(image_anim3, NULL, ecran,&pos_image_anim3); 
SDL_BlitSurface(texte,NULL, ecran,&position); 
SDL_Flip(ecran); 
SDL_Delay(500);
SDL_BlitSurface(image_anim4, NULL, ecran,&pos_image_anim4); 
SDL_BlitSurface(texte,NULL, ecran,&position); 
SDL_Flip(ecran); 
SDL_Delay(500);
SDL_BlitSurface(image_anim5, NULL, ecran,&pos_image_anim5);
SDL_BlitSurface(texte,NULL, ecran,&position); 
SDL_Flip(ecran); 
SDL_Delay(500);
SDL_BlitSurface(image_anim6, NULL, ecran,&pos_image_anim6);
SDL_BlitSurface(texte,NULL, ecran,&position); 
SDL_Flip(ecran); 

SDL_FreeSurface(image_anim1);
SDL_FreeSurface(image_anim2);
SDL_FreeSurface(image_anim3);
SDL_FreeSurface(image_anim4);
SDL_FreeSurface(image_anim5);
SDL_FreeSurface(image_anim6);

SDL_FreeSurface(texte);
}
