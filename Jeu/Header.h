
#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<string.h>

#ifdef _WIN32

#define lin 0
#include<Windows.h>

#endif
#ifdef __linux__ 

#define lin 1


#endif // 


struct sets
{
	int taille;
	int theme;
	int start;
	int gamemode;

};

struct coo
{
	int x;
	int y;
	int n;
	int j;
};





SDL_Window* fenetre = NULL;
SDL_Surface* surfacef = NULL;
SDL_Surface* base = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* textinit1 = NULL;
SDL_Surface* surfinit1 = NULL;
SDL_Rect destinit1;



SDL_Surface* surfaceFOND = NULL;
SDL_Surface* surfaceREJOUER = NULL;
SDL_Surface* surfaceQUITTER = NULL;


struct sets MENU();

SDL_Surface* surface4 = NULL;

SDL_Surface* surface5 = NULL;
SDL_Surface* surface6 = NULL;
SDL_Surface* surface7 = NULL;
SDL_Surface* surface8 = NULL;
SDL_Surface* surface9 = NULL;
SDL_Surface* surface10 = NULL;

SDL_Surface* surface11 = NULL;

SDL_Surface* surface5S = NULL;
SDL_Surface* surface6S = NULL;
SDL_Surface* surface7S = NULL;
SDL_Surface* surface8S = NULL;
SDL_Surface* surface9S = NULL;
SDL_Surface* surface10S = NULL;

SDL_Surface* surface11S = NULL;

SDL_Texture* texture4 = NULL;

SDL_Texture* texture5 = NULL;
SDL_Texture* texture6 = NULL;
SDL_Texture* texture7 = NULL;
SDL_Texture* texture8 = NULL;
SDL_Texture* texture9 = NULL;
SDL_Texture* texture10 = NULL;

SDL_Texture* texture11 = NULL;

SDL_Texture* texture5S = NULL;
SDL_Texture* texture6S = NULL;
SDL_Texture* texture7S = NULL;
SDL_Texture* texture8S = NULL;
SDL_Texture* texture9S = NULL;
SDL_Texture* texture10S = NULL;

SDL_Texture* texture11S = NULL;

SDL_Window* window = NULL;

SDL_Surface* surface = NULL;
SDL_Texture* texture = NULL;

SDL_Surface* surface1 = NULL;  //surface pour boutons jouer
SDL_Surface* surface2 = NULL;  // pour options
SDL_Surface* surface3 = NULL;  // quitter

SDL_Texture* texture1 = NULL;  //texture des boutons normaux 
SDL_Texture* texture2 = NULL;
SDL_Texture* texture3 = NULL;

SDL_Surface* surfaceSELECTION1 = NULL;      //surface pour boutons sélectionner
SDL_Surface* surfaceSELECTION2 = NULL;
SDL_Surface* surfaceSELECTION3 = NULL;

SDL_Texture* textureSELECTION1 = NULL;
SDL_Texture* textureSELECTION2 = NULL;
SDL_Texture* textureSELECTION3 = NULL;

SDL_Surface* surfaceBLACK1 = NULL;
SDL_Surface* surfaceBLACK2 = NULL;
SDL_Surface* surfaceBLACK3 = NULL;
SDL_Surface* surfaceBLACK4 = NULL;
SDL_Surface* surfaceBLACK5 = NULL;
SDL_Surface* surfaceBLACK6 = NULL;
SDL_Surface* surfaceBLACK7 = NULL;
SDL_Surface* surfaceBLACK8 = NULL;
SDL_Surface* surfaceBLACK9 = NULL;
SDL_Surface* surfaceBLACK10 = NULL;

SDL_Texture* textureBLACK1 = NULL;
SDL_Texture* textureBLACK2 = NULL;
SDL_Texture* textureBLACK3 = NULL;
SDL_Texture* textureBLACK4 = NULL;
SDL_Texture* textureBLACK5 = NULL;
SDL_Texture* textureBLACK6 = NULL;
SDL_Texture* textureBLACK7 = NULL;
SDL_Texture* textureBLACK8 = NULL;
SDL_Texture* textureBLACK9 = NULL;
SDL_Texture* textureBLACK10 = NULL;







struct sets MENU();


void SELECTIONtab(int tab[], SDL_Window* window, struct coo position, SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Texture* textureSELECTION1, SDL_Rect rect1, SDL_Texture* texture2, SDL_Texture* textureSELECTION2, SDL_Rect rect2, SDL_Texture* texture3, SDL_Texture* textureSELECTION3, SDL_Rect rect3, SDL_Rect rect4, SDL_Rect rect5, SDL_Rect rect6, SDL_Texture* texture, SDL_Texture* texture11, SDL_Texture* texture11S, SDL_Rect rectDUO, SDL_Rect rectDUOS, struct sets sets, SDL_Texture* textureBLACK1, SDL_Texture* textureBLACK2, SDL_Texture* textureBLACK3, SDL_Texture* textureBLACK4);
struct coo deplacementTABoptions(int tabOPTIONS[][3], struct coo position, SDL_Event event);
struct coo positionTABLEAUoptions(int tabOPTIONS[][3], struct coo position);
void afficherTABoptions(int tabOPTIONS[][3]);

void SELECTIONtabOPTIONS(int tabOPTIONS[][3], SDL_Renderer* renderer, SDL_Texture* texture4, SDL_Texture* texture5, SDL_Texture* texture6,
	SDL_Texture* texture7, SDL_Texture* texture8, SDL_Texture* texture9, SDL_Texture* texture10, SDL_Rect rect1, SDL_Rect rect2, SDL_Rect rect3, SDL_Rect rect4,
	SDL_Rect rect5, SDL_Rect rect6, SDL_Texture* texture5S, SDL_Texture* texture6S,
	SDL_Texture* texture7S, SDL_Texture* texture8S, SDL_Texture* texture9S, SDL_Texture* texture10S,struct sets sets);

void sauvgdSETTINGS(int tabOPTIONS[][3], struct sets sets);

struct coo positionTABLEAU(int tab[], struct coo position);

struct coo deplacementTAB(int tab[], struct coo position, SDL_Event event);
void afficherTAB(int tab[]);