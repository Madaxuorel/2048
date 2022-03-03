#include"Header.h"


int main(int argc, char* args[])
{

	int tab[4][4] = { {0,0} }; // tableau du joueur 1
	int tabj[4][4] = { {0,0} };// Tableau du joueur 2

	int gagne = 0;

	int score1 = 0;
	int score2 = 0;

	SDL_Rect rectscore;
	rectscore.x = 0;
		rectscore.y = 0;
		rectscore.h = 0;
		rectscore.w = 0;

	struct cooscore cooa;
	struct coo coodep1;
	struct coo coodep2;
	struct coo new;
	struct sets sets;
	struct win win;

	char scorestring[1000];
	FILE* sauv = NULL;
	FILE* settings = NULL;

	
	sets = getsets(); // Lit le fichier "settings.txt" pour récuperer les options, les met dans une variable de type struct sets.


	init(sets);// Crée la fenetre en fonction des options demandées

	SDL_BlitSurface(base, NULL, surfacef, NULL);
	SDL_UpdateWindowSurface(fenetre);

	
	int tab42j[32] = { 0 };
	// Ce tableaux sont les tableaux dans lesquels sera chargé la sauvegarde
	
	gettab2j(tab42j);// Charge la sauvegarde

	loadMedia(sets); // Charge l'image de fond 
	clock_t time = clock();

	if ( tabzero(tab42j)) // Si la sauvegarde est vide, 
	{

		initdeuxjoueurs( tabj, tab); // Crée les deux cases de départ

		affscore(0, 1,rectscore); // Affiche le socre (nul)
		affscore(0, 2,rectscore); 

		printf("\n\n");
	}
	else
	{
		transf2j(tab42j, tab, tabj); // Si une sauvegarde existe, on charge la sauvegarde dans les deux tableaux 
	}

	printf("\n\n");
	for (int u = 0; u < 4; u++)
	{
		printf("\n");
		for (int r = 0; r < 4; r++)
		{
			printf("%d ", tab[u][r]);
		}
	}
	printf("\n\n");
	for (int u = 0; u < 4; u++)
	{
		printf("\n");
		for (int r = 0; r < 4; r++)
		{
			printf("%d ", tabj[u][r]);
		}
	}
	printf("\n\n");

	AppliquerGraph2j(tab, tabj); // Met le contenu des tableaux sur la fenetre SDL
	win.cont = 1;
	int comp = 1;
	int cont = 1;
	int res = 0;
	int nonew;
	cooa.score = 0;
	int eventtest = 0;
	int joueur = 1;
	while (cont && gagne == 0 && win.cont) // boucle de jeu
	{
		win.cont = 1;
		comp = 0;
		eventtest = 0;
		SDL_Surface* icon = NULL;               //icone de la fenêtre
		icon = SDL_LoadBMP("2048PICTURES/logo-2048.bmp");
		SDL_SetWindowIcon(fenetre, icon);
		SDL_FreeSurface(icon);                //on libère l'icon

	
		SDL_Delay(100);
		res = 0;

		nonew = 0;
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case(SDL_KEYDOWN): // Si l'utilisateur presse une touche
				if (event.key.keysym.sym == SDLK_LEFT) // Si la touche est la flèche de gauche
				{


					eventtest = 1;

					if (joueur == 2) // Si le joueur  qui joue est le joueur 2 on modifie le tableau du J2
					{
						printf("\n gauche J2\n");
						for (int y = 1; y < 4; y++)
						{
							for (int i = 0; i < 4; i++)
							{
								if (tabj[i][y] != 0)
								{
									comp++;
									int t = 1;

									cooa = gauchemvt(tabj, i, y, tabj[i][y], t, cooa);

									tabj[cooa.x][cooa.y] = cooa.n;


								}
							}



						}

					}
					else if (joueur == 1)//Si le joueur qui joue est le joueur 1 on modifie le tableau du J1
					{
						printf("\n gauche J1\n");
						for (int y = 1; y < 4; y++)
						{
							for (int i = 0; i < 4; i++)
							{
								if (tab[i][y] != 0)
								{
									comp++;
									int t = 1;

									cooa = gauchemvt(tab, i, y, tab[i][y], t, cooa);

									tab[cooa.x][cooa.y] = cooa.n;


								}
							}



						}
						
					}




				}
				else if (event.key.keysym.sym == SDLK_RIGHT) // Si la touche pressée est la flèche du haut
				{

					eventtest = 1;
					if (joueur == 2)
					{
						for (int y = 2; y >= 0; y--)
						{
							for (int i = 0; i < 4; i++)
							{

								if (tabj[i][y] != 0)
								{
									comp++;
									int t = 1;
									cooa = droitemvt(tabj, i, y, tabj[i][y], t, cooa);
									tabj[cooa.x][cooa.y] = cooa.n;


								}
							}
						}
					}


					if (joueur == 1)
					{
						for (int y = 2; y >= 0; y--)
						{
							for (int i = 0; i < 4; i++)
							{

								if (tab[i][y] != 0)
								{
									comp++;
									int t = 1;
									cooa = droitemvt(tab, i, y, tab[i][y], t, cooa);
									tab[cooa.x][cooa.y] = cooa.n;


								}
							}
						}
					}
					


				}
				else if (event.key.keysym.sym == SDLK_UP)// Si la touche pressé est la fleche du haut
				{

					eventtest = 1;
					if (joueur == 2)
					{

						for (int i = 1; i < 4; i++)
						{
							for (int y = 0; y < 4; y++)
							{

								if (tabj[i][y] != 0)
								{
									comp++;
									int t = 1;
									cooa = hautmvt(tabj, i, y, tabj[i][y], t, cooa);
									tabj[cooa.x][cooa.y] = cooa.n;

								}
							}
						}
					}

					if (joueur == 1)
					{

						for (int i = 1; i < 4; i++)
						{
							for (int y = 0; y < 4; y++)
							{

								if (tab[i][y] != 0)
								{
									comp++;
									int t = 1;
									cooa = hautmvt(tab, i, y, tab[i][y], t, cooa);
									tab[cooa.x][cooa.y] = cooa.n;






								}
							}
						}
					}
					

				}

				else if (event.key.keysym.sym == SDLK_DOWN)// Si la touche pressée est la fleche du bas
				{

					eventtest = 1;
					if (joueur == 2)
					{

						for (int i = 2; i >= 0; i--)
						{
							for (int y = 0; y < 4; y++)
							{

								if (tabj[i][y] != 0)
								{

									comp++;
									int t = 1;
									cooa = basmvt(tabj, i, y, tabj[i][y], t, cooa);

									tabj[cooa.x][cooa.y] = cooa.n;

								}
							}
						}
					}
					if (joueur == 1)
					{
						for (int i = 2; i >= 0; i--)
						{
							for (int y = 0; y < 4; y++)
							{

								if (tab[i][y] != 0)
								{

									comp++;
									int t = 1;
									cooa = basmvt(tab, i, y, tab[i][y], t, cooa);

									tab[cooa.x][cooa.y] = cooa.n;






								}
							}
						}
					}
					


				}
				else if (event.key.keysym.sym == SDLK_ESCAPE) // Si la touche pressée est la touche échap
				{

					cont = 0;
					resetsets(); // Remet les option à 0 0 0
					SDL_QUIT;
					exit(0);
				}
				else if (event.key.keysym.sym == SDLK_s)// Si la touche pressée est la touche "s"
				{

					sauvgd(tab, tabj); // Sauvegarde les tableaux dans le fichier "sauv2j.txt"
					nonew = 1;
				}
				else if (event.key.keysym.sym == SDLK_r)// Si la touche pressée est la touche "r"
				{

					reset(tab, tabj); // Remet le tableeau à 0
					cooa.score = 0;// Remet le score à 0
					res = 1;
					nonew = 1;
				}
				else
				{
					nonew = 1;

				}



					// Affiche le score en fonction du joueur
					if (joueur == 1)
					{
						score1 = cooa.score;
					}
					else if (joueur == 2)
					{
						score2 = cooa.score;
					}


				
				fflush(stdout);
				printf("\n score1 = %d, score2 = %d \n", score1, score2);

				// Ajoute une case au hasard
				if ( nonew == 0)
				{

					if (joueur == 2)
					{
						printf("\n nouveau j2\n");
						time = clock();
						new = randstart(time);
						while (tabj[new.x][new.y] != 0)
						{
							time = clock();
							new = randstart(time);
						}
						tabj[new.x][new.y] = new.n;
					}
					else if (joueur == 1)
					{
						printf("\n nouveau J1\n");
						time = clock();
						new = randstart(time);
						while (tab[new.x][new.y] != 0)
						{
							time = clock();
							new = randstart(time);
						}
						tab[new.x][new.y] = new.n;
					}

					
					// Affiche les tableaux sur la fenetre
					AppliquerGraph2j(tab, tabj);

					
						affscore(score1, 1,rectscore);
						affscore(score2, 2,rectscore);
					

						//Met à jour le score
						if (joueur == 1)
						{
							score1 = cooa.score;
						}
						else if (joueur == 2)
						{
							score2 = cooa.score;
						}


					

					if (nonew != 1)
					{
						printf("\n\n");
						for (int u = 0; u < 4; u++)
						{
							printf("\n");
							for (int r = 0; r < 4; r++)
							{
								printf("%d ", tab[u][r]);
							}
						}
						printf("\n\n");
						for (int u = 0; u < 4; u++)
						{
							printf("\n");
							for (int r = 0; r < 4; r++)
							{
								printf("%d ", tabj[u][r]);
							}
						}
						printf("\n\n");
					}
				}






				break;

			}
		}

		if (nonew == 0 && eventtest == 1)
		{

			// Change le score
			joueur = inverse(joueur);
			printf("\n au joueur %d de jouer\n", joueur);
			
				win = fin2j(tab, tabj);
				win = afficherMENUfin(win, tab,score1,score2, rectscore, tabj, joueur);

		}

	}


	_sleep(100);
	printf("\nreset\n");
	resetsauv();
	resetsets();

	return 0;

}

struct coo randstart(clock_t clock)
{
	struct coo coo;
	srand(clock);
	coo.x = (rand() % (4 - 1 + 1)) + 1;
	coo.y = (rand() % (4 - 1 + 1)) + 1;

	srand(clock);
	coo.n = (rand() % (2 - 1 + 1)) + 1;
	if (coo.n == 1)
	{
		coo.n = 2;
	}
	else {
		coo.n = 4;
	}

	return coo;
}



Afftab(int tab[4][4])
{
	for (int u = 0; u < 4; u++)
	{
		printf("\n");
		for (int r = 0; r < 4; r++)
		{
			printf("%d ", tab[u][r]);
		}
	}

}




void sauvgd(int tab[4][4], int tab2[4][4])
{
	FILE* file = NULL;
	file = fopen("sauv2j.txt", "w");
	printf("\nSauvegarde en cours ...\n");
	char string[999];
	// écrit les valeurs des deux tableaux
	sprintf(string, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\0", tab[0][0], tab[0][1], tab[0][2], tab[0][3], tab[1][0], tab[1][1], tab[1][2], tab[1][3], tab[2][0], tab[2][1], tab[2][2], tab[2][3], tab[3][0], tab[3][1], tab[3][2], tab[3][3], tab2[0][0], tab2[0][1], tab2[0][2], tab2[0][3], tab2[1][0], tab2[1][1], tab2[1][2], tab2[1][3], tab2[2][0], tab2[2][1], tab2[2][2], tab2[2][3], tab2[3][0], tab2[3][1], tab2[3][2], tab2[3][3]);
	printf("( %s )\n", string);
	fputs(string, file);
	fclose(file);

}


int init(struct sets sets)
{


	int s = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Initialisation impossible");
		s = 0;
	}
	else
	{

		fenetre = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, NULL /*SDL_WINDOW_FULLSCREEN*/);
		if (fenetre == NULL)
		{
			printf("créer la fenetre est impossible");
			s = 0;
		}
		else
		{

			surfacef = SDL_GetWindowSurface(fenetre);
		}



	}
	SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
	TTF_Init();

	return s;
}



int loadMedia(struct sets sets)
{


	int s = 1;

	switch (sets.theme)
	{
	case 0:
		printf("\n1\n");
		base = SDL_LoadBMP("2048PICTURES/1V1.bmp");
		if (base == NULL)
		{
			printf("impossible de charger l'image, le PATH peut être faux");
			s = 0;
		}
		break;


	case 1:
		printf("\n2\n");
		base = SDL_LoadBMP("2048PICTURES/1V1.bmp");
		if (base == NULL)
		{
			printf("impossible de charger l'image, le PATH peut être faux");
			s = 0;
		}
		break;
	}


	return s;
}

struct cooscore gauchemvt(int tab[4][4], int i, int y, int n, int t, struct cooscore cooa)
{

	if (y == 0)// La récurrence s'arrete si la case est à la limite du tableau 
	{

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;

		return cooa;
	}
	if (tab[i][y - 1] == 0) // La case à coté de la case à déplacer est vide, on déplace la case
	{
		



		tab[i][y] = 0;


		tab[i][y - 1] = n;
		t++;
		gauchemvt(tab, i, y - 1, n, t + 1, cooa);
	}
	else if (tab[i][y - 1] == n)// La case à coté de la case à déplacer à la même valeur que la case à deplacer , on double la valeur
	{


		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i][y - 1] = n;

		gauchemvt(tab, i, y - 1, n, t + 1, cooa);
	}
	else if (tab[i][y - 1] != 0 && tab[i][y - 1] != n)// 
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	else
		return cooa;


}






struct cooscore droitemvt(int tab[4][4], int i, int y, int n, int t, struct cooscore cooa)// Pareil que gauchemvt
{

	if (y == 3)
	{

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	if (tab[i][y + 1] == 0)
	{



		tab[i][y] = 0;


		tab[i][y + 1] = n;
		t++;
		droitemvt(tab, i, y + 1, n, t + 1, cooa);
	}
	else if (tab[i][y + 1] == n)
	{


		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i][y + 1] = n;

		droitemvt(tab, i, y + 1, n, t + 1, cooa);
	}
	else if (tab[i][y + 1] != 0 && tab[i][y + 1] != n)
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	else
		return cooa;
}




struct cooscore hautmvt(int tab[4][4], int i, int y, int n, int t, struct cooscore cooa)// Pareil que gauchemvt
{


	if (i == 0)
	{
		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	if (tab[i - 1][y] == 0)
	{



		tab[i][y] = 0;


		tab[i - 1][y] = n;
		t++;
		hautmvt(tab, i - 1, y, n, t + 1, cooa);
	}
	else if (tab[i - 1][y] == n)
	{

		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i - 1][y] = n;

		hautmvt(tab, i - 1, y, n, t + 1, cooa);
	}
	else if (tab[i][y] != 0 && tab[i - 1][y] != n)
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	else
		return cooa;
}


void gettab(int ints[16])// Charge la sauvegarde
{

	FILE* file = NULL;

	if (!(file = fopen("sauv.txt", "r")))
	{
		fclose(file);
		return;
	}
	char string[100] = "";
	fgets(string, 100, file);

	ints[0] = atoi(strtok(string, " "));
	for (int k = 1; k < 16; k++)
	{
		ints[k] = atoi(strtok(NULL, " "));
	}
	fclose(file);
	return;

}

int tabzero(int tab4[16])// Detecte si le tableau est vide
{
	int c = 0;
	for (int i = 0; i < 16; i++)
	{
		if (tab4[i] == 0)
		{
			c++;
		}
	}



	if (c == 16)
	{
		return 1;

	}
	else {
		return 0;
	}

}


struct cooscore basmvt(int tab[4][4], int i, int y, int n, int t, struct cooscore cooa)// Pareil que gauchemvt
{

	if (i == 3)
	{

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	if (tab[i + 1][y] == 0)
	{




		tab[i][y] = 0;


		tab[i + 1][y] = n;
		t++;
		basmvt(tab, i + 1, y, n, t + 1, cooa);
	}
	else if (tab[i + 1][y] == n)
	{


		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i + 1][y] = n;

		basmvt(tab, i + 1, y, n, t + 1, cooa);
	}
	else if (tab[i][y] != 0 && tab[i + 1][y] != n)
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
	else
		return cooa;
}
void close(int tab[4][4])
{

	SDL_Quit();
	TTF_Quit();

	free(tab);
	SDL_DestroyWindow(fenetre);
	SDL_DestroyTexture(textinit1);
	SDL_FreeSurface(surfacef);

}


void reset(int tab[4][4], int tab2[4][4])// Recommence la partie
{
	struct coo coodep1;
	struct coo coodep2;
	clock_t  time = clock();
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			tab[i][y] = 0;
		}

	}

	coodep1 = randstart(time);
	tab[coodep1.y - 1][coodep1.x - 1] = coodep1.n;
	_sleep(50);
	time = clock();
	coodep2 = randstart(time);

	tab[coodep2.y - 1][coodep2.x - 1] = coodep2.n;


	
	  time = clock();
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			tab2[i][y] = 0;
		}

	}

	coodep1 = randstart(time);
	tab2[coodep1.y - 1][coodep1.x - 1] = coodep1.n;
	_sleep(50);
	time = clock();
	coodep2 = randstart(time);

	tab2[coodep2.y - 1][coodep2.x - 1] = coodep2.n;

	AppliquerGraph2j(tab, tab2);


}

void resetsauv()// Vide la sauvegarde
{
	FILE* file = NULL;
	file = fopen("sauv2j.txt", "w+");
	char string[200] = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ";
	fputs(string, file);
	fclose(file);
}



void affscore(int score, int j ,SDL_Rect rectscore)//Affiche la sauvegarde
{

	police = TTF_OpenFont("police_score.ttf", 33);

	char scorestring[100];
	sprintf(scorestring, "%d", score);


	texte = TTF_RenderText_Solid(police, scorestring, couleurBlanche);
	if (j == 1)
	{
		rectscore.x = 333;
		rectscore.y = 33;
	}
	else if (j == 2)
	{
		rectscore.x = 830;
		rectscore.y = 33;
	}
	

	SDL_BlitSurface(texte, NULL, surfacef, &rectscore);
	SDL_UpdateWindowSurface(fenetre);

}


struct sets getsets()// Lit les options
{
	struct sets sets;
	sets.gamemode = sets.start = sets.taille = sets.theme = 0;
	FILE* file = NULL;

	if (!(file = fopen("settings.txt", "r")))
	{
		fclose(file);
		return sets;
	}
	char string[100] = "";
	fgets(string, 100, file);

	sets.gamemode = atoi(strtok(string, " "));
	sets.taille = atoi(strtok(NULL, " "));
	sets.theme = atoi(strtok(NULL, " "));
	fclose(file);
	printf("\ngamemode = %d\n", sets.gamemode);
	printf("\ntheme = %d\n", sets.theme);
	return sets;

}

void resetsets()//VIde les options
{
	FILE* fileSETTINGS = NULL;
	fileSETTINGS = fopen("settings.txt", "w");

	char string[100];

	sprintf(string, "0 4 0");
	fputs(string, fileSETTINGS);
	fclose(fileSETTINGS);

}

void initdeuxjoueurs( int tabj[4][4], int tab[4][4])// Initilaise les tableaux
{
	clock_t time = clock();
	struct coo coo11, coo12, coo21, coo22;
	coo11.j = 1;
	coo12.j = 1;
	coo22.j = 2;
	coo21.j = 2;

	coo11 = randstart(time);
	tab[coo11.y - 1][coo11.x - 1] = coo11.n;

	time = clock();
	coo12 = randstart(time);

	tab[coo12.y - 1][coo12.x - 1] = coo12.n;




	coo22.j = 2;
	coo21.j = 2;
	
	coo21 = randstart(time);
	tabj[coo21.y - 1][coo21.x - 1] = coo21.n;

	time = clock();
	coo22 = randstart(time);

	tabj[coo22.y - 1][coo22.x - 1] = coo22.n;




	AppliquerGraph2j(tab, tabj);

}

void AppliquerGraph2j(int tab1[4][4], int tabj[4][4])// Affaiche les tableaux ssur la fenetre SDL
{

	SDL_BlitSurface(base, NULL, surfacef, NULL);
	struct coo coo1;
	struct coo coo2;
	SDL_Rect dest1;
	SDL_Rect dest2;

	int c = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int w = 0; w < 4; w++)
		{
			if (tab1[i][w] != 0)// Pour chaque case non vide,
			{
				c++;
				coo1.x = i;
				coo1.y = w;
				coo1.n = tab1[i][w];

				coo1.x++;
				coo1.y++;

				coo1 = apply2j(coo1, 1);//transforme les coordnoées en "language SDL"

				dest1.x = coo1.y;
				dest1.y = coo1.x;
				dest1.w = 114;
				dest1.h = 114;

				SDL_BlitSurface(surfinit1, NULL, surfacef, &dest1);
				SDL_UpdateWindowSurface(fenetre);
			}
		}

	}


	c = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int w = 0; w < 4; w++)
		{
			if (tabj[i][w] != 0)
			{
				c++;
				coo2.x = i;
				coo2.y = w;
				coo2.n = tabj[i][w];

				coo2.x++;
				coo2.y++;

				coo2 = apply2j(coo2, 2);

				dest2.x = coo2.y;
				dest2.y = coo2.x;
				dest2.w = 114;
				dest2.h = 114;

				SDL_BlitSurface(surfinit1, NULL, surfacef, &dest2);
				SDL_UpdateWindowSurface(fenetre);
			}
		}

	}

}


struct coo apply2j(struct coo coo, int j)// Modifie les coordonées
{
	if (j == 1)
	{

		switch (coo.y)
		{
		case 1:
			coo.y = 40;
			break;
		case 2:
			coo.y = 165;
			break;
		case 3:
			coo.y = 290;
			break;
		case 4:
			coo.y = 405;
			break;
		}
		switch (coo.x)
		{
		case 1:
			coo.x = 85;
			break;
		case 2:
			coo.x = 212;
			break;
		case 3:
			coo.x = 341;
			break;
		case 4:
			coo.x = 460;
			break;
		}
	}
	else
	{
		switch (coo.y)
		{
		case 1:
			coo.y = 682;
			break;
		case 2:
			coo.y = 802;
			break;
		case 3:
			coo.y = 922;
			break;
		case 4:
			coo.y = 1047;
			break;
		}

		switch (coo.x)
		{
		case 1:
			coo.x = 85;
			break;
		case 2:
			coo.x = 212;
			break;
		case 3:
			coo.x = 341;
			break;
		case 4:
			coo.x = 460;
			break;

		}

	}

	//chargments des textures des tuiles

	if (coo.n == 2)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/2.bmp");

	}
	else if (coo.n == 4)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/4.bmp");
	}
	else if (coo.n == 8)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/8.bmp");
	}
	else if (coo.n == 16)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/16.bmp");
	}
	else if (coo.n == 32)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/32.bmp");
	}
	else if (coo.n == 64)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/64.bmp");
	}
	else if (coo.n == 128)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/128.bmp");
	}
	else if (coo.n == 256)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/256.bmp");
	}
	else if (coo.n == 1024)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/1024.bmp");
	}
	else if (coo.n == 2048)
	{

		surfinit1 = SDL_LoadBMP("2048PICTURES/2048.bmp");
	}


	return coo;
}


void gettab2j(int tab[32])//  Charge la sauvegarde
{
	FILE* file = NULL;

	if (!(file = fopen("sauv2j.txt", "r")))
	{
		fclose(file);
		return;
	}
	char string[100] = "";
	fgets(string, 100, file);

	tab[0] = atoi(strtok(string, " "));
	for (int k = 1; k < 32; k++)
	{
		tab[k] = atoi(strtok(NULL, " "));
	}
	fclose(file);
	return;

}

void transf2j(int entree[32], int sortie1[4][4], int sortie2[4][4])// Met la sauvegarde dans les tableaux de jeu

{

	for (int u = 0; u < 4; u++)
	{
		sortie1[0][u] = entree[u];
	}
	for (int yu = 4; yu < 8; yu++)
	{
		sortie1[1][yu - 4] = entree[yu];

	}
	for (int cont = 8; cont < 12; cont++)
	{
		sortie1[2][cont - 8] = entree[cont];
	}
	for (int ye = 12; ye < 16; ye++)
	{
		sortie1[3][ye - 12] = entree[ye];
	}
	for (int ku = 16; ku < 20; ku++)
	{
		sortie2[0][ku - 16] = entree[ku];
	}
	for (int yu = 20; yu < 24; yu++)
	{
		sortie2[1][yu - 20] = entree[yu];

	}
	for (int cont = 24; cont < 28; cont++)
	{
		sortie2[2][cont - 24] = entree[cont];
	}
	for (int ye = 28; ye < 32; ye++)
	{
		sortie2[3][ye - 28] = entree[ye];
	}

}

int inverse(int j)// Change le joueur qui joue
{
	if (j == 1)
	{
		return 2;
	}
	else if (j == 2)
	{
		return 1;
	}
	else {
		return 0;
	}

}



struct win fin2j(int tab1[4][4], int tab2[4][4]) // Vérifiee les conditions de fin
{
	struct win win;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (tab1[i][y] != 0)
			{
				c1++;          //on compte le nombre de case remplit du j1
			}

			if (tab1[i][y] == 2048)
			{
				c3++;			// si il y a présence ou non du nombre 2048
			}

		}


	}

	for (int i = 0; i < 4; i++) // pareil que pour j1 mais pour j2
	{
		for (int y = 0; y < 4; y++)
		{
			if (tab2[i][y] != 0)
			{
				c2++;		
			}
			if (tab2[i][y] == 2048)
			{
				c4++;
			}


		}

	}
	if (c1 == 16)	// si le tab du j1 est plein le j2 gagner
	{
		win.cont = 0;
		win.gagne = 2;
		return win;
	}
	else if (c2 == 16) // si le tab du j2 est plein le j1 gagner
	{
		win.cont = 0;
		win.gagne = 1;
		return win;
	}
	else if (c3 >= 1) // si présence de 2048 dans tab du j1 il gagne
	{
		win.cont = 0;
		win.gagne = 1;
		return win;
	}
	else if (c4 >= 1) // si présence de 2048 dans tab du j2 il gagne
	{
		win.cont = 0;
		win.gagne = 2;
		return win;
	}
	else  // sinon le jeu continue
	{
	win.cont = 1; 
	win.gagne = 0;
	}

	return win;
}

struct win afficherMENUfin(struct win win, int tab[][4], int score1,int score2, SDL_Rect rectscore, int tabj[][4],int joueur)
{

	if (win.cont == 1) {						//cas ou la partie continue , on affiche pas de menu de fin
		return win;  // le jeu continue
	}

	if (win.cont == 0 && win.gagne != 0)		//si la partie est finie , on affiche un menu de fin
	{
		SDL_Surface* surfaceREJOUER = NULL;
		SDL_Surface* surfaceQUITTER = NULL;

		surfaceREJOUER = SDL_LoadBMP("2048PICTURES/fin1.bmp");	//initialisation des textures du menu
		surfaceQUITTER = SDL_LoadBMP("2048PICTURES/fin2.bmp");

		SDL_Rect RectFOND;										//zone du menu
		RectFOND.x = 450;
		RectFOND.y = 170;
		RectFOND.w = 358;
		RectFOND.h = 295;

		SDL_BlitSurface(surfaceREJOUER,NULL,surfacef , &RectFOND);

		int tabFIN[2];								//pour ce déplacer dans le menu
		tabFIN[0] = 1;
		tabFIN[1] = 0;

		int menuFIN = 1;
		SDL_Event eventFIN;

		while (menuFIN)							//boucle du choix de si on veut rejouer ou quitter
		{
			
			SDL_UpdateWindowSurface(fenetre);

			SDL_WaitEvent(&eventFIN);			//on recupère les inputs gauche ou droute
			switch (eventFIN.key.keysym.sym)
			{
			case(SDLK_RIGHT):
				if (tabFIN[1] != 1)				//si flèche droite on déplace le chiffre 1 dans la deuxième case
				{
					SDL_BlitSurface(surfaceQUITTER,NULL,surfacef , &RectFOND);	//texture du menu
					AscoreFINAL(win,score1,score2,rectscore);					//texte du menu
					tabFIN[0] = 0;												// déplacement
					tabFIN[1] = 1;
				}

				break;

			case(SDLK_LEFT):				// si flèche gauche on déplace le chiffre 1 dans la première case
				if (tabFIN[0] != 1)
				{
					SDL_BlitSurface(surfaceREJOUER,NULL,surfacef , &RectFOND);
					AscoreFINAL(win,score1,score2,rectscore);
					tabFIN[1] = 0;
					tabFIN[0] = 1;
				}

				break;
			case(SDLK_RETURN):

				if (tabFIN[0] == 1)					//si jamais on re joue
				{
					reset(tab, tabj);				// on reset puis re-rentre dans la boucle de jeu
					win.cont = 1;
					return win;
					menuFIN = 0;					//on sort de la boucle de ce menu

				}

				if (tabFIN[1] == 1)
				{
					win.cont = 0;				//si jamais on quitte
					return win;
					menuFIN = 0;				//on sort de toute les boucles , fin du jeu

				}
			}
			printf("\n");
			printf("%d\n", tabFIN[0]);
			printf("%d\n", tabFIN[1]);

		}
	}
}

void AscoreFINAL(struct win win, int score1, int score2, SDL_Rect rectscore)  // permet d'afficher le score sur le menu de fin
{
		SDL_Surface* texte = NULL;
		TTF_Font* police = NULL;

		SDL_Color couleurBlanche = { 255, 255, 255 };	
		police = TTF_OpenFont("police_score.ttf", 33);		// on met la police au format ttf(SDL_tff) dans une variable

		char annoncefin[100] = "oui";						//tableau initialisé pour la phrase de fin

		rectscore.x = 180;
		rectscore.y = 300;

		if (win.gagne == 1)									//si le joueur 1 gagne			
		{
			char finstring[100] = "Le joueur 1 l'emporte ! :";	//phrase pour j1
			sprintf(annoncefin, "%s", finstring);				//on met cette phrase dans le tableau précédent
			printf("%d", score1);
			affscore(score1, 1,rectscore);						//affichage du score

		}
		else if (win.gagne == 2)								//même chose que pour le j1 mais pour le j2
		{
			char finstring[100] = "Le joueur 2 l'emporte ! :";
			sprintf(annoncefin, "%s", finstring);
			affscore(score2, 2,rectscore);
		}

		texte = TTF_RenderText_Solid(police, annoncefin, couleurBlanche);	//on charge notre texte 
		SDL_Rect recttext;

		recttext.x = 550;
		recttext.y = 250;

		SDL_BlitSurface(texte, NULL, surfacef, &recttext);					//on affichage le texte		

		SDL_UpdateWindowSurface(fenetre);									
}