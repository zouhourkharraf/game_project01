#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include"prototypes.h"

int main(int argc, char* argv[])
{

//(initialisation des surfaces), Le pointeur qui va stocker la surface 
SDL_Surface *ecran=NULL,*bg_menu=NULL,*bouton1=NULL,*bouton2=NULL,*bouton3=NULL,*bouton4=NULL,*bouton5=NULL,*bg_play=NULL,*bg_options=NULL,*bg_tutorial=NULL;
SDL_Surface *texte=NULL;// initialisation de la surface du texte

SDL_Surface *bouton2_vers2=NULL,*bouton3_vers2=NULL,*bouton4_vers2=NULL;

TTF_Font *police = NULL; //inisialisation de la police (Le pointeur qui va stocker la poclice)
SDL_Rect position;//La position du texte

 //les position des images à superposer(surfaces)
SDL_Rect pos_bg_menu,pos_bouton1,pos_bouton2,pos_bouton3,pos_bouton4,pos_bouton5,pos_bg_play,pos_bg_options,pos_bg_tutorial,pos_click;

SDL_Rect pos_bouton2_vers2,pos_bouton3_vers2,pos_bouton4_vers2;

//affectation des valeus de position(x , y)
   pos_bg_menu.x = 0;
   pos_bg_menu.y = 0;
   pos_bouton1.x = 300;
   pos_bouton1.y = 50;
   pos_bouton2.x = 299;
   pos_bouton2.y = 144;
   pos_bouton3.x = 299;
   pos_bouton3.y = 228;
   pos_bouton4.x = 299;
   pos_bouton4.y = 315;
   pos_bouton5.x = 299;
   pos_bouton5.y = 396;
   
   pos_bouton2_vers2.x=299;
   pos_bouton2_vers2.y=144;
   pos_bouton3_vers2.x=299;
   pos_bouton3_vers2.y=228;
   pos_bouton4_vers2.x=299;
   pos_bouton4_vers2.y=315;

    pos_bg_play.x =0;
    pos_bg_play.y =0;
    pos_bg_options.x=0;
    pos_bg_options.y=0;
    pos_bg_tutorial.x=0;
    pos_bg_tutorial.y =0;


    position.x = 600; //Postion du texte
   position.y = 500; //Postion du texte    


TTF_Init(); //Démarrer SDL_ttf


SDL_Init(SDL_INIT_VIDEO);   // Initialisation de la SDL. 
SDL_WM_SetIcon(IMG_Load("m.png"), NULL);//charger l'icone     

ecran=SDL_SetVideoMode(800,536,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);// une fenêtre redimensionnable de taille initiale 800*536 (32 bits / pixel) en mémoire vidéo, avec le double buffering activé. (iciOn tente d'ouvrir une fenêtre)

SDL_WM_SetCaption("toto's Adventure", NULL);//ajouter un nom et une icone à la fenêtre(maintenant c'est à NULL)

police = TTF_OpenFont("hellojones.ttf",22); //charger la police
SDL_Color couleurNoire = {0, 0, 0};//une variable qui stocke la couleur noire 
texte=TTF_RenderText_Blended(police,"© one piece 2021", couleurNoire); // écrire un texte en noir dans une SDL_Surface texte en mode blended

//jouer de la musique
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer avec une fréquence de 44.1 KHz et un nombre de bits = 1024
   {
      printf("%s", Mix_GetError());//connaître les erreur si ils existent
   }
Mix_Music *musique; //Création du pointeur de type Mix_Music
musique = Mix_LoadMUS("musique.mp3"); //Chargement de la musique
Mix_PlayMusic(musique, -1); //Jouer infiniment la musique


//gestion des évennement

int continuer = 1; // le booléen pour la continuité de la boucle 


//Assembler des surfaces dans la fenêtre
bg_menu = IMG_Load("background.png");// Chargement d'un PNG avec IMG_Load
SDL_BlitSurface(bg_menu, NULL, ecran,&pos_bg_menu);
SDL_BlitSurface(texte,NULL, ecran,&position); /* Blit du texte */
SDL_Flip(ecran);


bouton1 = IMG_Load("bouton_menu.png");
bouton2 = IMG_Load("bouton_play.png");
bouton3 = IMG_Load("bouton_options.png");
bouton4 = IMG_Load("bouton_tutorial.png");
bouton5 = IMG_Load("bouton_quit.png");
SDL_BlitSurface(bouton1, NULL, ecran,&pos_bouton1);
SDL_BlitSurface(bouton2, NULL, ecran,&pos_bouton2);
SDL_BlitSurface(bouton3, NULL, ecran,&pos_bouton3); 
SDL_BlitSurface(bouton4, NULL, ecran,&pos_bouton4); 
SDL_BlitSurface(bouton5, NULL, ecran,&pos_bouton5);
SDL_Flip(ecran);

while(continuer) 
   { 
animation(ecran);


SDL_Event event; // déclaration de la vairable qui sert à gérer les événements
while(SDL_PollEvent(&event)) /* On attend un événement qu'on récupère dans event */  
{
SDL_BlitSurface(bouton1, NULL, ecran,&pos_bouton1);
SDL_BlitSurface(bouton2, NULL, ecran,&pos_bouton2);
SDL_BlitSurface(bouton3, NULL, ecran,&pos_bouton3); 
SDL_BlitSurface(bouton4, NULL, ecran,&pos_bouton4);
SDL_BlitSurface(bouton5, NULL, ecran,&pos_bouton5);


       switch(event.type) //tester le type d'événement
       {
           case SDL_QUIT:// Si c'est un événement QUITTER 

               continuer=0; //continuer =0 donc le boucle va s'arrêter
                break;
           case SDL_KEYDOWN:
               switch (event.key.keysym.sym)
                 {
                    case SDLK_ESCAPE: //si on Appui sur la touche Echap,le programme s'arrête
                    continuer = 0;
                    break;
        
                 }
            break;
           case SDL_MOUSEBUTTONUP:
              pos_click.x = event.button.x;
              pos_click.y = event.button.y;
           if((event.button.button == SDL_BUTTON_LEFT)&& ((pos_click.x >299)&&(pos_click.x <500)&&( pos_click.y >144)&&( pos_click.y <205) ) )
             {
                 bg_play= IMG_Load("background_play.png");
                 SDL_BlitSurface(bg_play, NULL, ecran,&pos_bg_play); SDL_Flip(ecran); 
                 SDL_Delay(150);
                    
              }
            else if((event.button.button == SDL_BUTTON_LEFT)&& ((pos_click.x >299)&&(pos_click.x <500)&&( pos_click.y >228)&&( pos_click.y <289) ) )
             {
                 bg_options= IMG_Load("background_options.png");
                 SDL_BlitSurface(bg_options, NULL, ecran,&pos_bg_options); SDL_Flip(ecran); 
                 SDL_Delay(150);
                   
              }
             else if((event.button.button == SDL_BUTTON_LEFT)&& ((pos_click.x >299)&&(pos_click.x <500)&&( pos_click.y >315)&&( pos_click.y <376) ) )
             {
                  bg_tutorial= IMG_Load("background_tutorial.png");
                 SDL_BlitSurface(bg_tutorial, NULL, ecran,&pos_bg_tutorial); SDL_Flip(ecran); 
                SDL_Delay(150);
                    
              }
             else if((event.button.button == SDL_BUTTON_LEFT)&& ((pos_click.x >299)&&(pos_click.x <500)&&( pos_click.y >396)&&( pos_click.y <457) ) )
             {
                   continuer = 0;
              }
            
           break;
	  case SDL_MOUSEMOTION:
		  if((event.motion.x>299)&&(event.motion.x<500) && (event.motion.y>144) &&(event.motion.y<205))
			{
			  
                 bouton2_vers2 = IMG_Load("bouton_play2.png");
                 SDL_BlitSurface( bouton2_vers2, NULL, ecran,&pos_bouton2_vers2); SDL_Flip(ecran); 
                
                 
			}
              else if((event.motion.x>299)&&(event.motion.x<500)&&(event.motion.y>228) &&(event.motion.y<289))
 		{
                  bouton3_vers2 = IMG_Load("bouton_options2.png");
                 SDL_BlitSurface( bouton3_vers2, NULL, ecran,&pos_bouton3_vers2);SDL_Flip(ecran); 
                     
                   
              }
		else if((event.motion.x>299)&&(event.motion.x<500)&&(event.motion.y>315) &&(event.motion.y<376))
 		{
                 bouton4_vers2 = IMG_Load("bouton_tutorial2.png");
                 SDL_BlitSurface( bouton4_vers2, NULL, ecran,&pos_bouton4_vers2); SDL_Flip(ecran); 
                 
               }
		break;   
           }

    }

}  

SDL_FreeSurface(bg_menu); //libérer la mémoire de L'image bg_menu
SDL_FreeSurface(bouton1); //libérer la mémoire de L'image bouton1
SDL_FreeSurface(bouton2); //libérer la mémoire de bouton2
SDL_FreeSurface(bouton3);
SDL_FreeSurface(bouton4);
SDL_FreeSurface(bouton5);
SDL_FreeSurface(bg_play);
SDL_FreeSurface(bg_tutorial);
SDL_FreeSurface(bg_options);


SDL_FreeSurface(bouton2_vers2);
SDL_FreeSurface(bouton3_vers2);
SDL_FreeSurface(bouton4_vers2);

SDL_FreeSurface(texte);

Mix_FreeMusic(musique); //Libération de la musique

Mix_CloseAudio(); //Fermeture de l'API

TTF_CloseFont(police); // Fermer la police
TTF_Quit(); //arrêter SDL_ttf,


SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).


 return EXIT_SUCCESS;  // Fermeture du programme
}

