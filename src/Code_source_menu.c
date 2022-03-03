#include"Header.h"


int main()
{
	//HWND windowHandle = GetConsoleWindow();
	//ShowWindow(windowHandle, SW_HIDE);

	struct sets sets;
	sets.gamemode = 0;
	sets = MENU();
	int t = lin;
	SDL_Quit();

	if (t == 1)
	{
		printf("\n Votre système n'est pas une version de windows, executer le programme est impossible");
		exit(0);
	}
	else if(t == 0)
	{
		if (sets.gamemode == 0)
		{
			system("ChangementNsingle");
		}
		else if (sets.gamemode == 1)
		{
			system("Multiplayer_2048.exe");
		}
	}

	return 0;
}


struct sets MENU()
{
	struct coo position;
	position.x = 0;
	position.y = 0;
	position.n = 1;

	int menu = 1;     
	int menuOptions = 0;

	struct sets sets;
	sets.theme = 0;
	sets.taille = 4;
	sets.start = 0;
	sets.gamemode = 0;

	window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 503, 503, 0); //création de la fenetre
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);	// création du renderer

	surface = SDL_LoadBMP("2048PICTURES/FOND.bmp");						//chargement de toute les textures,surface
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface1 = SDL_LoadBMP("2048PICTURES/solo.bmp");
	surface11 = SDL_LoadBMP("2048PICTURES/duo.bmp");
	surface2 = SDL_LoadBMP("2048PICTURES/options.bmp");
	surface3 = SDL_LoadBMP("2048PICTURES/quitter.bmp");

	surfaceSELECTION1 = SDL_LoadBMP("2048PICTURES/soloS.bmp");
	surface11S = SDL_LoadBMP("2048PICTURES/duoS.bmp");
	surfaceSELECTION2 = SDL_LoadBMP("2048PICTURES/SELECTIONoptions.bmp");
	surfaceSELECTION3 = SDL_LoadBMP("2048PICTURES/SELECTIONquitter.bmp");

	texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
	texture11 = SDL_CreateTextureFromSurface(renderer, surface11);
	texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	texture3 = SDL_CreateTextureFromSurface(renderer, surface3);

	textureSELECTION1 = SDL_CreateTextureFromSurface(renderer, surfaceSELECTION1);
	texture11S = SDL_CreateTextureFromSurface(renderer, surface11S);
	textureSELECTION2 = SDL_CreateTextureFromSurface(renderer, surfaceSELECTION2);
	textureSELECTION3 = SDL_CreateTextureFromSurface(renderer, surfaceSELECTION3);

	surfaceBLACK1 = SDL_LoadBMP("2048PICTURES/menuCOMPLETB1.bmp");
	surfaceBLACK2 = SDL_LoadBMP("2048PICTURES/menuCOMPLETB2.bmp");
	surfaceBLACK3 = SDL_LoadBMP("2048PICTURES/menuCOMPLETB3.bmp");
	surfaceBLACK4 = SDL_LoadBMP("2048PICTURES/menuCOMPLETB4.bmp");

	surfaceBLACK5 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB1.bmp");
	surfaceBLACK6 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB2.bmp");
	surfaceBLACK7 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB3.bmp");
	surfaceBLACK8 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB4.bmp");
	surfaceBLACK9 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB5.bmp");
	surfaceBLACK10 = SDL_LoadBMP("2048PICTURES/menuOPTIONSB6.bmp");

	textureBLACK1 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK1);
	textureBLACK2 =	SDL_CreateTextureFromSurface(renderer, surfaceBLACK2);
	textureBLACK3 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK3);
	textureBLACK4 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK4);

	textureBLACK5 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK5);
	textureBLACK6 =	SDL_CreateTextureFromSurface(renderer, surfaceBLACK6);
	textureBLACK7 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK7);
	textureBLACK8 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK8);
	textureBLACK9 = SDL_CreateTextureFromSurface(renderer, surfaceBLACK9);
	textureBLACK10= SDL_CreateTextureFromSurface(renderer, surfaceBLACK10);

	SDL_FreeSurface(surfaceBLACK1);
	SDL_FreeSurface(surfaceBLACK2);
	SDL_FreeSurface(surfaceBLACK3);
	SDL_FreeSurface(surfaceBLACK4);

	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface11);
	SDL_FreeSurface(surface2);
	SDL_FreeSurface(surface3);

	SDL_FreeSurface(surfaceSELECTION1);
	SDL_FreeSurface(surface11S);
	SDL_FreeSurface(surfaceSELECTION2);
	SDL_FreeSurface(surfaceSELECTION3);

	int tab[4] = { 0 };  //tab du menu principal

	tab[0] = position.n;

	int tabOPTIONS[3][2] = { {0},{0} };  // tab du menu options
	tabOPTIONS[0][0] = 1;

	tabOPTIONS[2][0] = 0;
	tabOPTIONS[2][1] = 0;

	SDL_Surface* icon = NULL;               //icone de la fenêtre
		icon = SDL_LoadBMP("2048PICTURES/logo-2048.bmp");
		SDL_SetWindowIcon(fenetre, icon);
		SDL_FreeSurface(icon);                //on libère l'icon


	for (int i = 0; i < 4; i++) {
		printf("%d", tab[i]);
	}
	while (menu == 1 || menuOptions == 1) //boucle principal du menu , on n'en sort dès qu'on est plus dans le menu principal ou celui des options
	{
		while (menu) {

			SDL_Rect rect1;			//rectangle définissant les différents boutons
			rect1.x = 175;
			rect1.y = 195;
			rect1.w = 149;
			rect1.h = 47;

			SDL_Rect rect2;
			rect2.x = 175;
			rect2.y = 311;
			rect2.w = 149;
			rect2.h = 47;

			SDL_Rect rect3;
			rect3.x = 175;
			rect3.y = 369;
			rect3.w = 149;
			rect3.h = 47;

			SDL_Rect rect4;
			rect4.x = 158;
			rect4.y = 195;
			rect4.w = 190;
			rect4.h = 59;

			SDL_Rect rect5;
			rect5.x = 158;
			rect5.y = 306;
			rect5.w = 190;
			rect5.h = 59;

			SDL_Rect rect6;
			rect6.x = 158;
			rect6.y = 364;
			rect6.w = 190;
			rect6.h = 59;

			SDL_Rect rectDUO;
			rectDUO.x = 175;
			rectDUO.y = 253;
			rectDUO.w = 149;
			rectDUO.h = 47;

			SDL_Rect rectDUOS;
			rectDUOS.x = 158;
			rectDUOS.y = 248;
			rectDUOS.w = 190;
			rectDUOS.h = 59;

			SELECTIONtab(tab, window, position, renderer, texture1, textureSELECTION1, rect1, texture2, textureSELECTION2, 
			rect2, texture3, textureSELECTION3, rect3, rect4, rect5, rect6, texture, texture11, texture11S, rectDUO, rectDUOS,sets,textureBLACK1,textureBLACK2,
			textureBLACK3,textureBLACK4);  // permet le passage d'un bouton à l'autre

			SDL_RenderPresent(renderer);

			SDL_Event event;			// on attend qu'une touche soit activé
			SDL_WaitEvent(&event);
			if (event.type == SDL_KEYDOWN)	
			{

				switch (event.key.keysym.sym)
				{
				case(SDLK_ESCAPE):		//si la touche est échape on quitte
					exit(1);
					break;
				case(SDLK_UP):			//fléche du haut ,on se déplace vers le haut dans le tableau et on affiche le bouton séléctionner
					position = positionTABLEAU(tab, position);
					position = deplacementTAB(tab, position, event);
					SELECTIONtab(tab, window, position, renderer, texture1, textureSELECTION1, rect1, texture2, textureSELECTION2, rect2, texture3, textureSELECTION3, rect3, rect4, rect5, rect6, texture, texture11, texture11S, rectDUO, rectDUOS,sets,textureBLACK1,textureBLACK2,textureBLACK3,textureBLACK4);
					afficherTAB(tab);
					break;

				case(SDLK_DOWN): // même idée vers le bas
					position = positionTABLEAU(tab, position);
					position = deplacementTAB(tab, position, event);
					SELECTIONtab(tab, window, position, renderer, texture1, textureSELECTION1, rect1, texture2, textureSELECTION2, rect2, texture3, textureSELECTION3, rect3, rect4, rect5, rect6, texture, texture11, texture11S, rectDUO, rectDUOS,sets,textureBLACK1,textureBLACK2,textureBLACK3,textureBLACK4);
					afficherTAB(tab);
					break;

				case(SDLK_RETURN): // le boutons rentré peut lancer le jeu , ouvrir les options ou quitter
					position = positionTABLEAU(tab, position);
					if (position.x == 0) // cas ou on clique sur jouer
					{
						sets.gamemode = 0;
						sauvgdSETTINGS(tabOPTIONS, sets);
						sets.start = 1; //on rentre dans la boucle de jeu

						menu = 0; // on sort de cette boucle
					}
					if (position.x == 1)
					{
						sets.gamemode = 1;	 // on rentre dans le mode duo
						sauvgdSETTINGS(tabOPTIONS, sets);
						sets.start = 1;
						menu = 0;

					}
					if (position.x == 2)
					{
						menuOptions = 1; // on rentre dans la boucle option qui suit
						menu = 0;
					}
					if (position.x == 3)
					{
						exit(1); // on quitte
						break;
					}
				}

			}

		}

		while (menuOptions == 1) {

			//chargement de toute les textures du menu options

			surface5 = SDL_LoadBMP("2048PICTURES/menuOPTIONS1.bmp"); 
			surface6 = SDL_LoadBMP("2048PICTURES/menuOPTIONS2.bmp");
			surface7 = SDL_LoadBMP("2048PICTURES/menuOPTIONS3.bmp");
			surface8 = SDL_LoadBMP("2048PICTURES/menuOPTIONS4.bmp");
			surface9 = SDL_LoadBMP("2048PICTURES/menuOPTIONS5.bmp");

			surface5S = SDL_LoadBMP("2048PICTURES/menuOPTIONSB1.bmp");
			surface6S = SDL_LoadBMP("2048PICTURES/menuOPTIONSB2.bmp");
			surface7S = SDL_LoadBMP("2048PICTURES/menuOPTIONSB3.bmp");
			surface8S = SDL_LoadBMP("2048PICTURES/menuOPTIONSB4.bmp");
			surface9S = SDL_LoadBMP("2048PICTURES/menuOPTIONSB5.bmp");


			texture5 = SDL_CreateTextureFromSurface(renderer, surface5);
			texture6 = SDL_CreateTextureFromSurface(renderer, surface6);
			texture7 = SDL_CreateTextureFromSurface(renderer, surface7);
			texture8 = SDL_CreateTextureFromSurface(renderer, surface8);
			texture9 = SDL_CreateTextureFromSurface(renderer, surface9);
			
			texture5S = SDL_CreateTextureFromSurface(renderer, surface5S);
			texture6S = SDL_CreateTextureFromSurface(renderer, surface6S);
			texture7S = SDL_CreateTextureFromSurface(renderer, surface7S);
			texture8S = SDL_CreateTextureFromSurface(renderer, surface8S);
			texture9S = SDL_CreateTextureFromSurface(renderer, surface9S);
	
			SDL_FreeSurface(surface5);
			SDL_FreeSurface(surface6);
			SDL_FreeSurface(surface7);
			SDL_FreeSurface(surface8);
			SDL_FreeSurface(surface9);

			SDL_FreeSurface(surface5S);
			SDL_FreeSurface(surface6S);
			SDL_FreeSurface(surface7S);
			SDL_FreeSurface(surface8S);
			SDL_FreeSurface(surface9S);
	
	
			SELECTIONtabOPTIONS(tabOPTIONS, renderer, texture4, texture5, texture6,texture7, texture8, texture9, texture10,texture5S, texture6S, texture7S, texture8S, texture9S, texture10S,sets);
			SDL_RenderPresent(renderer);

			SDL_Event event; // même chose que le premier menu , on attend un évenement
			SDL_WaitEvent(&event);
			position = positionTABLEAUoptions(tabOPTIONS, position); // en fonction de la touche , on se déplace dans le tableau

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case(SDLK_ESCAPE):

					exit(1); // on peut toujours quitter avec echap
					break;

				case(SDLK_UP):

					position = deplacementTABoptions(tabOPTIONS, position, event);
					afficherTABoptions(tabOPTIONS);
					break;

				case(SDLK_DOWN):

					position = deplacementTABoptions(tabOPTIONS, position, event);
					afficherTABoptions(tabOPTIONS);
					break;

				case(SDLK_RIGHT):

					position = deplacementTABoptions(tabOPTIONS, position, event);
					afficherTABoptions(tabOPTIONS);
					break;

				case(SDLK_LEFT):

					position = deplacementTABoptions(tabOPTIONS, position, event);
					afficherTABoptions(tabOPTIONS);
					break;

				case(SDLK_RETURN):		// avec entré on peut modifier les options par la valeur des variables

					if (tabOPTIONS[0][0] == 1)
					{
						sets.taille = 4; // mode 4x4

					}
					if (tabOPTIONS[0][1] == 1)
					{
						sets.taille = 5; // mode 5x5
					}

					if (tabOPTIONS[1][0] == 1)
					{
						sets.theme = 0; // theme light
					}
					if (tabOPTIONS[1][1] == 1)
					{
						sets.theme = 1;	// theme dark
					}

					if (tabOPTIONS[2][0] == 1 || tabOPTIONS[2][1] == 1) // les deux dernière cases du tableau correspondent au bouton retour qui nous fait quitter cette boucle
					{
						menu = 1;
						menuOptions = 0;
						sauvgdSETTINGS(tabOPTIONS, sets);
					}
				}
			}
		}
	}

	return sets;

}

struct coo positionTABLEAU(int tab[], struct coo position) // simple boucle for qui nous permet de voir la position dans le tab du menu principal
{
	for (int i = 0; i < 4; i++)
	{
		if (tab[i] == 1) {
			position.x = i;
		}
	}
	return position;
}

struct coo deplacementTAB(int tab[], struct coo position, SDL_Event event) // déplacement dans le menu principal
{
	if (event.key.keysym.sym == SDLK_UP)  // les mouvements haut et bas sont réguler par la taille du tableau
	{
		if (position.x > 0)
		{
			tab[position.x] = 0;
			tab[position.x - 1] = 1;
		}
	}

	if (event.key.keysym.sym == SDLK_DOWN)
	{
		if (position.x < 3)
		{
			tab[position.x] = 0;
			tab[position.x + 1] = 1;
		}
	}
	return position;
}

void afficherTAB(int tab[])
{
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("%d", tab[i]);
	}
}

//pour afficher le bouton séléctionner (en jaune)
void SELECTIONtab(int tab[], SDL_Window* window, struct coo position, SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Texture* textureSELECTION1, SDL_Rect rect1, SDL_Texture* texture2, SDL_Texture* textureSELECTION2, SDL_Rect rect2, SDL_Texture* texture3, SDL_Texture* textureSELECTION3, SDL_Rect rect3, SDL_Rect rect4, SDL_Rect rect5, SDL_Rect rect6, SDL_Texture* texture, SDL_Texture* texture11, SDL_Texture* texture11S, SDL_Rect rectDUO, SDL_Rect rectDUOS,struct sets sets, SDL_Texture* textureBLACK1,SDL_Texture* textureBLACK2,SDL_Texture* textureBLACK3,SDL_Texture* textureBLACK4)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	
	if (sets.theme == 0) // theme light 
	{
		if (tab[0] == 1)
		{
			SDL_RenderCopy(renderer, textureSELECTION1, NULL, &rect4); // on affiche le bouton séléctionner et les autres non selectionner 
																		// cas du bouton jouer
			SDL_RenderCopy(renderer, texture11, NULL, &rectDUO);
			SDL_RenderCopy(renderer, texture2, NULL, &rect2);
			SDL_RenderCopy(renderer, texture3, NULL, &rect3);
		}

		if (tab[1] == 1)									//bouton duo
		{
			SDL_RenderCopy(renderer, texture11S, NULL, &rectDUOS);

			SDL_RenderCopy(renderer, texture2, NULL, &rect2);
			SDL_RenderCopy(renderer, texture1, NULL, &rect1);
			SDL_RenderCopy(renderer, texture3, NULL, &rect3);
		}

		if (tab[2] == 1)		//boutons options
		{	
			SDL_RenderCopy(renderer, textureSELECTION2, NULL, &rect5);

			SDL_RenderCopy(renderer, texture3, NULL, &rect3);
			SDL_RenderCopy(renderer, texture1, NULL, &rect1);
			SDL_RenderCopy(renderer, texture11, NULL, &rectDUO);

		}
		if (tab[3] == 1)		//boutons quitter
		{
			SDL_RenderCopy(renderer, textureSELECTION3, NULL, &rect6);

			SDL_RenderCopy(renderer, texture11, NULL, &rectDUO);
			SDL_RenderCopy(renderer, texture1, NULL, &rect1);
			SDL_RenderCopy(renderer, texture2, NULL, &rect2);
		}
	}
	if (sets.theme == 1) // dark theme , même chose pour chaque cas (jouer,duo...)
	{
		if (tab[0] == 1)
		{
			SDL_RenderCopy(renderer, textureBLACK1, NULL, NULL);		// au lieu d'utilsier 5 images comme précédemment on en utilise plus qu'une (nouvelle méthode)
		}

		if (tab[1] == 1)
		{
			SDL_RenderCopy(renderer, textureBLACK2, NULL, NULL);
		}

		if (tab[2] == 1)
		{
			SDL_RenderCopy(renderer, textureBLACK3, NULL, NULL);
		}
		if (tab[3] == 1)
		{
			SDL_RenderCopy(renderer, textureBLACK4, NULL, NULL);
		}
	}

}
// Ici on retrouve une série defonction similaire a celles du menu principal mais pour les options

struct coo positionTABLEAUoptions(int tabOPTIONS[][2], struct coo position) //s
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (tabOPTIONS[i][j] == 1)
			{
				position.x = i;
				position.y = j;
			}
		}
	}
	return position;
}

struct coo deplacementTABoptions(int tabOPTIONS[][2], struct coo position, SDL_Event event) 
{
	if (event.key.keysym.sym == SDLK_UP)
	{
		if (position.x > 0)
		{
			tabOPTIONS[position.x][position.y] = 0;
			tabOPTIONS[position.x - 1][position.y] = 1;
		}
	}

	if (event.key.keysym.sym == SDLK_DOWN)
	{
		if (position.x < 2)
		{
			tabOPTIONS[position.x][position.y] = 0;
			tabOPTIONS[position.x + 1][position.y] = 1;
		}
	}

	if (event.key.keysym.sym == SDLK_RIGHT)
	{
		if (position.y < 1)
		{
			tabOPTIONS[position.x][position.y] = 0;
			tabOPTIONS[position.x][position.y + 1] = 1;
		}
	}

	if (event.key.keysym.sym == SDLK_LEFT)
	{
		if (position.y > 0)
		{
			tabOPTIONS[position.x][position.y] = 0;
			tabOPTIONS[position.x][position.y - 1] = 1;
		}
	}
	return position;
}

void afficherTABoptions(int tabOPTIONS[][2])
{
	int i = 0;
	int j = 0;

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("\n");
		for (j = 0; j < 2; j++) {
			printf("%7d", tabOPTIONS[i][j]);
		}
	}
}
void SELECTIONtabOPTIONS(int tabOPTIONS[][2], SDL_Renderer* renderer, SDL_Texture* texture4, SDL_Texture* texture5, SDL_Texture* texture6,
	SDL_Texture* texture7, SDL_Texture* texture8, SDL_Texture* texture9, SDL_Texture* texture10, SDL_Texture* texture5S, SDL_Texture* texture6S,
	SDL_Texture* texture7S, SDL_Texture* texture8S, SDL_Texture* texture9S, SDL_Texture* texture10S,struct sets sets)
{
	if (sets.theme == 0)
	{
		if (tabOPTIONS[2][0] == 1 || tabOPTIONS[2][1] == 1)
		{
			SDL_RenderCopy(renderer, texture9, NULL, NULL);
		
		}
		if (tabOPTIONS[0][0] == 1)
		{
			SDL_RenderCopy(renderer, texture5, NULL, NULL);
		}
		if (tabOPTIONS[0][1] == 1)
		{
			SDL_RenderCopy(renderer, texture6, NULL, NULL);
		}
		if (tabOPTIONS[1][0] == 1)
		{
			SDL_RenderCopy(renderer, texture7, NULL, NULL);
		}
		if (tabOPTIONS[1][1] == 1)
		{
			SDL_RenderCopy(renderer, texture8, NULL, NULL);
		}
	}

	if(sets.theme == 1)
	{
		if (tabOPTIONS[2][0] == 1 || tabOPTIONS[2][1] == 1)
		{
			SDL_RenderCopy(renderer, texture9S, NULL, NULL);
		}
		if (tabOPTIONS[0][0] == 1)
		{
			SDL_RenderCopy(renderer, texture5S, NULL, NULL);
		}
		if (tabOPTIONS[0][1] == 1)
		{
			SDL_RenderCopy(renderer, texture6S, NULL, NULL);
		}
		if (tabOPTIONS[1][0] == 1)
		{
			SDL_RenderCopy(renderer, texture7S,NULL, NULL);
		}
		if (tabOPTIONS[1][1] == 1)
		{
			SDL_RenderCopy(renderer, texture8S, NULL, NULL);
		}
		
	}

}

void sauvgdSETTINGS(int tabOPTIONS[][2], struct sets sets) // permet de sauvegarder les options 
{
	FILE* fileSETTINGS = NULL;                    
	fileSETTINGS = fopen("settings.txt", "w");		// on ouvre le fichier de sauvegarde
	printf("\n%d\n", sets.gamemode);
	char string[100];								

	sprintf(string, "%d %d %d\0", sets.gamemode, sets.taille, sets.theme); 
	printf("( %s )\n", string);
	fputs(string, fileSETTINGS);
	fclose(fileSETTINGS);
}
