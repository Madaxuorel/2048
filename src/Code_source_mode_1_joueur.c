#include"Header.h"


int main(int argc, char* args[])
{
	
	int tab[6][6] = { {0,0} };// Tableau de jeu


	int gagne = 0;


	struct cooscore cooa;
	struct coo coodep1;
	struct coo coodep2;
	struct coo new;
	struct sets sets;


	char scorestring[1000];
	FILE* sauv = NULL;
	FILE* settings = NULL;


	
	sets = getsets();//Charge les options dans une varibale de type struct sets
	int n = 4;
	SDL_Rect rectscore;

	
	init(sets, n);// Crée la fenetre en fonction des options 

	SDL_BlitSurface(base, NULL, surfacef, NULL);
	SDL_UpdateWindowSurface(fenetre);

	int tab4[36] = { 0 };// Tableau de sauvegarde

	gettab(tab4, n);// Charge le tableau de sauvegarde



	loadMedia(sets,n);// Charge le fond 

	clock_t time = clock();



	if (tabzero(tab4, n))// Si la sauvegard est vide, on intialise une nouvelle partie
	{
		loadMedia(sets, n);
		coodep1 = randstart(time, n);

		tab[coodep1.y - 1][coodep1.x - 1] = coodep1.n;




	

		time = clock();
		coodep2 = randstart(time, n);

		tab[coodep2.y - 1][coodep2.x - 1] = coodep2.n;



		
	}
	else
	{

		transf(tab4, tab, n);// Sinon on  charge la sauvegarde




	}

	printf("tab0 = \n");
	for (int k = 0; k < n; k++)
	{
		printf("\n");
		for (int w = 0; w < n; w++)
		{
			printf("%d ", tab[k][w]);
		}
	}




	AppliquerGraph(tab, n);// On affiche le tableau sur la fenetre



	int cont = 1;
	int nonew;
	cooa.score = 0;
	int eventtest = 0;

	while (cont && gagne == 0) // boucle de jeu
	{
		eventtest = 0;
		SDL_Surface* icon = NULL;               //icone de la fenêtre
		icon = SDL_LoadBMP("2048PICTURES/logo-2048.bmp");
		SDL_SetWindowIcon(fenetre, icon);
		SDL_FreeSurface(icon);                //on libère l'icon



		nonew = 0;
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case(SDL_KEYDOWN):// Si l'utilisateur appuie sur une touche 
				if (event.key.keysym.sym == SDLK_LEFT)// Si la touche est la flèche de gauche
				{
					printf("\ngauche\n");
					eventtest = 1;




					for (int y = 1; y < n; y++)
					{
						for (int i = 0; i < n; i++)
						{
							if (tab[i][y] != 0) // on modife chaque case non vide
							{
								int t = 1;

								cooa = gauchemvt(tab, i, y, tab[i][y], t, cooa);

								tab[cooa.x][cooa.y] = cooa.n;


							}
						}



					}




				}
				else if (event.key.keysym.sym == SDLK_RIGHT)// Si la touche est la flèche de droite
				{
					printf("\ndroite\n");
					eventtest = 1;


					for (int y = n/2; y >= 0; y--)
					{
						for (int i = 0; i < n; i++)
						{

							if (tab[i][y] != 0)
							{

								int t = 1;
								cooa = droitemvt(tab, i, y, tab[i][y], t, cooa, n);
								tab[cooa.x][cooa.y] = cooa.n;


							}
						}
					}

				}
				else if (event.key.keysym.sym == SDLK_UP)// Si la touche est la flèche du haut
				{
					printf("\nhaut\n");
					eventtest = 1;



					for (int i = 1; i < n; i++)
					{
						for (int y = 0; y <n; y++)
						{

							if (tab[i][y] != 0)
							{

								int t = 1;
								cooa = hautmvt(tab, i, y, tab[i][y], t, cooa);
								tab[cooa.x][cooa.y] = cooa.n;






							}
						}
					}
				}

				else if (event.key.keysym.sym == SDLK_DOWN)// Si la touche est la flèche du bas
				{
					printf("\nbas\n");
					eventtest = 1;



					for (int i = n/2; i >= 0; i--)
					{
						for (int y = 0; y < n; y++)
						{

							if (tab[i][y] != 0)
							{


								int t = 1;
								cooa = basmvt(tab, i, y, tab[i][y], t, cooa, n);

								tab[cooa.x][cooa.y] = cooa.n;






							}
						}
					}
				}
				else if (event.key.keysym.sym == SDLK_ESCAPE)// Si la touche est échap
				{
					cont = 0;
					resetsets();// on vide les options
					SDL_QUIT;
					exit(0);
				}

				else if (event.key.keysym.sym == SDLK_r)// Si la touche est "r"
				{
					reset(tab, n);// On recommence la partie
					cooa.score = 0;
					nonew = 1;
				}



				else if (event.key.keysym.sym == SDLK_s)// Si la touche est "s"
				{
					sauvgd(tab, n);// On sauvegarde
					nonew = 1;
				}
				else
				{
					nonew = 1;

				}



				printf("tab1 = \n");
				for (int k = 0; k < n; k++)
				{
					printf("\n");
					for (int w = 0; w < n; w++)
					{
						printf("%d ", tab[k][w]);
					}
				}




				printf("\n\n");


				
					AppliquerGraph(tab, n);// On affiche le tableau sur la fenetre
				

					if (n == 4)
					{
						rectscore.x = 353;
						rectscore.y = 33;
					}
					else if (n == 5)
					{
						printf("\noui\n");
						rectscore.x = 493;
						rectscore.y = 48;
					}
				


				




				if (nonew == 0 && sets.gamemode == 0) // On crée une nouvelle tuile à a fin du tour
				{
					printf("\nnew\n");
					time = clock();
					new = randstart(time, n);
					while (tab[new.x][new.y] != 0)
					{
						time = clock();
						new = randstart(time, n);
					}
					tab[new.x][new.y] = new.n;
				}






				AppliquerGraph(tab, n);



				affscore(cooa.score, rectscore);// On affiche le score





				break;

			}
		}


		if (nonew == 0 && eventtest == 1)
		{
			cont = fin(tab, n);
		}
		rectscore.x = 280;
		rectscore.y = 300;
		cont = afficherMENUfin(cont, tab, cooa, rectscore, n);

	}

	// On vide la sauvegarde et les options
	resetsauv();
	resetsets();


	return 0;
}


struct coo randstart(clock_t clock, int n)// Génere une nouvelle tuile
{
	struct coo coo;
	srand(clock);
	
	coo.x = (rand() % (n - 1 + 1)) + 1;
	coo.y = (rand() % (n - 1 + 1)) + 1;

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
void sauvgd(int tab[6][6], int n)// Sauvegarde le tableau ( en fontion de la taille du tableau)
{
	FILE* file = NULL;
	file = fopen("sauv.txt", "w");
	printf("\nSauvegarde en cours ...\n");
	char string[1000];

	switch (n)
	{
	case 4:
		sprintf(string, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \0", tab[0][0], tab[0][1], tab[0][2], tab[0][3], tab[1][0], tab[1][1], tab[1][2], tab[1][3], tab[2][0], tab[2][1], tab[2][2], tab[2][3], tab[3][0], tab[3][1], tab[3][2], tab[3][3]);
		printf("( %s )\n", string);
		fputs(string, file);
		fclose(file);
		break;
	case 5:
		sprintf(string, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d 0 0 0 0 0 0 0 0 0 0 0 \0", tab[0][0], tab[0][1], tab[0][2], tab[0][3],tab[0][4], tab[1][0], tab[1][1], tab[1][2], tab[1][3],tab[1][4], tab[2][0], tab[2][1], tab[2][2], tab[2][3],tab[2][4], tab[3][0], tab[3][1], tab[3][2], tab[3][3],tab[3][4], tab[4][0], tab[4][1], tab[4][2], tab[4][3], tab[4][4]);
		printf("( %s )\n", string);
		fputs(string, file);
		fclose(file);
		break;
	case 6:
		sprintf(string, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\0", tab[0][0], tab[0][1], tab[0][2], tab[0][3], tab[0][4], tab[1][0], tab[1][1], tab[1][2], tab[1][3],tab[1][4], tab[2][0], tab[2][1], tab[2][2], tab[2][3], tab[2][4], tab[3][0], tab[3][1], tab[3][2], tab[3][3], tab[3][4], tab[4][0], tab[4][1], tab[4][2], tab[4][3], tab[4][4], tab[5][0], tab[5][1], tab[5][2], tab[5][3], tab[5][4], tab[5][5]);
		printf("( %s )\n", string);
		fputs(string, file);
		fclose(file);
	}


}

int init(struct sets sets, int n)// Crée la fenetre
{


	int s = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Initialisation impossible");
		s = 0;
	}
	else
	{
		switch (n)
		{
		case 4:
			fenetre = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, NULL /*SDL_WINDOW_FULLSCREEN*/);
			break;
		case 5:
			printf("\nrentré\n");
			fenetre = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 750, NULL /*SDL_WINDOW_FULLSCREEN*/);
			break;
		case 6:
			fenetre = SDL_CreateWindow("2048", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900,  NULL);
			break;
		}
	
		
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

int loadMedia(struct sets sets, int n)// Charge le fond
{
	int s = 1;

	switch (n)
	{
	case  4:


		switch (sets.theme)
		{
		case 0:
			base = SDL_LoadBMP("2048PICTURES/plan2.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;


		case 1:
			base = SDL_LoadBMP("2048PICTURES/plan2D.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;
		}


		break;
	case 5:
		
		switch (sets.theme)
		{
		case 0:
	
			base = SDL_LoadBMP("2048PICTURES/5x5JEU.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;


		case 1:
			base = SDL_LoadBMP("2048PICTURES/5x5JEUB.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;
		}

		break;
	case 6:
		switch (sets.theme)
		{
		case 0:
			base = SDL_LoadBMP("2048PICTURES/6x6JEU.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;


		case 1:
			base = SDL_LoadBMP("2048PICTURES/6x6JEUB.bmp");
			if (base == NULL)
			{
				printf("impossible de charger l'image, le PATH peut être faux");
				s = 0;
			}
			break;
		}
		break;

	}








	return s;
}

void gettab(int ints[36], int n) // Charge la sauvegarde
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
	for (int k = 1; k < n*n; k++)
	{
		ints[k] = atoi(strtok(NULL, " "));
	}
	fclose(file);
	return;

}

int tabzero(int tab4[36], int n) // Vérifie si le tableau est vide
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

struct coo apply(struct coo coo, int n)// Traduit les coordonées en pixels et charge les images (en fonction de taille)
{

	switch (n)
	{
	case 4:
		switch (coo.x)
		{
		case 1:
			coo.x = 95;
			break;
		case 2:
			coo.x = 221;
			break;
		case 3:
			coo.x = 345;
			break;
		case 4:
			coo.x = 465;
			break;
		}

		switch (coo.y)
		{
		case 1:
			coo.y = 62;
			break;
		case 2:
			coo.y = 185;
			break;
		case 3:
			coo.y = 305;
			break;
		case 4:
			coo.y = 427;
			break;
		}

		switch (coo.n)
		{
		case 2:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2.bmp");
			break;
		case 4:
			surfinit1 = SDL_LoadBMP("2048PICTURES/4.bmp");
			break;
		case 8:
			surfinit1 = SDL_LoadBMP("2048PICTURES/8.bmp");
			break;

		case 16:
			surfinit1 = SDL_LoadBMP("2048PICTURES/16.bmp");
			break;

		case 32:
			surfinit1 = SDL_LoadBMP("2048PICTURES/32.bmp");
			break;

		case 64:
			surfinit1 = SDL_LoadBMP("2048PICTURES/64.bmp");
			break;

		case 128:
			surfinit1 = SDL_LoadBMP("2048PICTURES/128.bmp");
			break;


		case 256:
			surfinit1 = SDL_LoadBMP("2048PICTURES/256.bmp");
			break;

		case 512:
			surfinit1 = SDL_LoadBMP("2048PICTURES/512.bmp");
			break;

		case 1024:
			surfinit1 = SDL_LoadBMP("2048PICTURES/1024.bmp");
			break;

		case 2048:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2048.bmp");
			break;
		}
		if (surfinit1 == NULL)
		{
			printf("impossible de charger la texture");
		}


		return coo;

		break;
	case 5:
		switch (coo.x)
		{
		case 1:
			coo.x = 105;
			break;
		case 2:
			coo.x = 225;
			break;
		case 3:
			coo.x = 355;
			break;
		case 4:
			coo.x = 480;
			break;
		case 5:
			coo.x = 605;
				break;
		}

		switch (coo.y)
		{
		case 1:
			coo.y = 70;
			break;
		case 2:
			coo.y = 195;
			break;
		case 3:
			coo.y = 320;
			break;
		case 4:
			coo.y = 445;
			break;
		case 5:
			coo.y = 570;
			break;
		}

		switch (coo.n)
		{
		case 2:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2.bmp");
			break;
		case 4:
			surfinit1 = SDL_LoadBMP("2048PICTURES/4.bmp");
			break;
		case 8:
			surfinit1 = SDL_LoadBMP("2048PICTURES/8.bmp");
			break;

		case 16:
			surfinit1 = SDL_LoadBMP("2048PICTURES/16.bmp");
			break;

		case 32:
			surfinit1 = SDL_LoadBMP("2048PICTURES/32.bmp");
			break;

		case 64:
			surfinit1 = SDL_LoadBMP("2048PICTURES/64.bmp");
			break;

		case 128:
			surfinit1 = SDL_LoadBMP("2048PICTURES/128.bmp");
			break;


		case 256:
			surfinit1 = SDL_LoadBMP("2048PICTURES/256.bmp");
			break;

		case 512:
			surfinit1 = SDL_LoadBMP("2048PICTURES/512.bmp");
			break;

		case 1024:
			surfinit1 = SDL_LoadBMP("2048PICTURES/1024.bmp");
			break;

		case 2048:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2048.bmp");
			break;
		}
		if (surfinit1 == NULL)
		{
			printf("impossible de charger la texture");
		}


		return coo;
		break;
	case 6:
		switch (coo.x)
		{
		case 1:
			coo.x = 105;
			break;
		case 2:
			coo.x = 230;
			break;
		case 3:
			coo.x = 350;
			break;
		case 4:
			coo.x = 475;
			break;
		case 5:
			
			coo.x = 600;
			
		case 6:
			coo.x = 720;
				break;
		}

		switch (coo.y)
		{
		case 1:
			coo.y = 85;
			break;
		case 2:
			coo.y = 210;
			break;
		case 3:
			coo.y = 335;
			break;
		case 4:
			coo.y = 460;
			break;
		case 5:
			printf("\ncase 5\n");
			coo.y = 585;
		case 6:
			coo.y = 710;
			break;
		}

		switch (coo.n)
		{
		case 2:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2.bmp");
			break;
		case 4:
			surfinit1 = SDL_LoadBMP("2048PICTURES/4.bmp");
			break;
		case 8:
			surfinit1 = SDL_LoadBMP("2048PICTURES/8.bmp");
			break;

		case 16:
			surfinit1 = SDL_LoadBMP("2048PICTURES/16.bmp");
			break;

		case 32:
			surfinit1 = SDL_LoadBMP("2048PICTURES/32.bmp");
			break;

		case 64:
			surfinit1 = SDL_LoadBMP("2048PICTURES/64.bmp");
			break;

		case 128:
			surfinit1 = SDL_LoadBMP("2048PICTURES/128.bmp");
			break;


		case 256:
			surfinit1 = SDL_LoadBMP("2048PICTURES/256.bmp");
			break;

		case 512:
			surfinit1 = SDL_LoadBMP("2048PICTURES/512.bmp");
			break;

		case 1024:
			surfinit1 = SDL_LoadBMP("2048PICTURES/1024.bmp");
			break;

		case 2048:
			surfinit1 = SDL_LoadBMP("2048PICTURES/2048.bmp");
			break;
		}
		if (surfinit1 == NULL)
		{
			printf("impossible de charger la texture");
		}


		return coo;
		break;
	}

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

struct cooscore gauchemvt(int tab[6][6], int i, int y, int n, int t, struct cooscore cooa)
{

	if (y == 0)// La récurrence s'arrete si la case est à la limite du tableau 
	{

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;

		return cooa;
	}
	if (tab[i][y - 1] == 0)// La case à coté de la case à déplacer est vide, on déplace la case
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
	else if (tab[i][y - 1] != 0 && tab[i][y - 1] != n)// La case à coté de la case à déplacer n'a pas la même valeur que la case à deplacer , on sort de la récurence
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}



}

void AppliquerGraph(int tab[6][6], int n)
{
	SDL_BlitSurface(base, NULL, surfacef, NULL);
	struct coo cooa;
	SDL_Rect dest;

	for (int i = 0; i < n; i++)
	{
		for (int w = 0; w < n; w++)
		{
			if (tab[i][w] != 0)
			{
				
				cooa.x = i;
				cooa.y = w;
				cooa.n = tab[i][w];

				cooa.x++;
				cooa.y++;

				cooa = apply(cooa, n);

				dest.x = cooa.y;
				dest.y = cooa.x;
				dest.w = 114;
				dest.h = 114;

				SDL_BlitSurface(surfinit1, NULL, surfacef, &dest);
				SDL_UpdateWindowSurface(fenetre);
			}
		}

	}

}




struct cooscore droitemvt(int tab[6][6], int i, int y, int n, int t, struct cooscore cooa, int k)// Pareil que gauche mvt
{

	if (y == k - 1)
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
		droitemvt(tab, i, y + 1, n, t + 1, cooa, k);
	}
	else if (tab[i][y + 1] == n)
	{


		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i][y + 1] = n;

		droitemvt(tab, i, y + 1, n, t + 1, cooa, k);
	}
	else if (tab[i][y + 1] != 0 && tab[i][y + 1] != n)
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
}




struct cooscore hautmvt(int tab[6][6], int i, int y, int n, int t, struct cooscore cooa)// Pareil que gauchemvt
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
}



struct cooscore basmvt(int tab[6][6], int i, int y, int n, int t, struct cooscore cooa, int k)// Pareil que gauchemvt
{

	if (i == k - 1)
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
		basmvt(tab, i + 1, y, n, t + 1, cooa,k);
	}
	else if (tab[i + 1][y] == n)
	{


		tab[i][y] = 0;


		n = 2 * n;
		cooa.score = cooa.score + n;
		tab[i + 1][y] = n;

		basmvt(tab, i + 1, y, n, t + 1, cooa,k);
	}
	else if (tab[i][y] != 0 && tab[i + 1][y] != n)
	{
		tab[i][y] = n;

		cooa.x = i;
		cooa.y = y;
		cooa.n = n;
		return cooa;
	}
}
int close(int tab[6][6])
{

	SDL_Quit();
	TTF_Quit();

	free(tab);
	SDL_DestroyWindow(fenetre);
	SDL_DestroyTexture(textinit1);
	SDL_FreeSurface(surfacef);

}


int fin(int tab[6][6], int n)// On vérifie les conditions de fin
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			if (tab[i][y] != 0)
			{
				c++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			if (tab[i][y] == 2048)
			{
				return 2;  // boucle pour savoir si on a gagner , si c'est le cas , cont=2
			}
		}
	}

	int k = n * n;

	if (c == k) //CHANGER
	{
	
		return 0;      // si cont=0 , la partie est finit (perdue)
	}
	else
	{
		return 1;   // si cont=1 , la partie continue
	}
}

void reset(int tab[6][6], int n)// On remet le tableau à zero et on recommence la partie
{
	struct coo coodep1;
	struct coo coodep2;
	clock_t  time = clock();
	for (int i = 0; i < n; i++)
	{
		for (int y = 0; y < n; y++)
		{
			tab[i][y] = 0;
		}

	}

	coodep1 = randstart(time,n);
	tab[coodep1.y - 1][coodep1.x - 1] = coodep1.n;
	_sleep(50);
	time = clock();
	coodep2 = randstart(time,n);

	tab[coodep2.y - 1][coodep2.x - 1] = coodep2.n;

	AppliquerGraph(tab, n);


}

void resetsauv()// On vide la sauvegarde
{
	FILE* file = NULL;
	file = fopen("sauv.txt", "w+");
	char string[55] = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ";
	fputs(string, file);
	fclose(file);
}



void affscore(int score, SDL_Rect rectscore)// Affiche le score
{
	SDL_Surface* texte = NULL;
	TTF_Font* police = NULL;
	SDL_Color couleurBlanche = { 255, 255, 255 };
	police = TTF_OpenFont("police_score.ttf", 33);

	char scorestring[100];
	sprintf(scorestring, "%d", score);
	

	texte = TTF_RenderText_Solid(police, scorestring, couleurBlanche);


	


	SDL_BlitSurface(texte, NULL, surfacef, &rectscore);
	SDL_UpdateWindowSurface(fenetre);

}


struct sets getsets()// On charge les options
{
	struct sets sets;
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

void resetsets()// On vide les options
{
	FILE* fileSETTINGS = NULL;
	fileSETTINGS = fopen("settings.txt", "w");

	char string[100];

	sprintf(string, "0 4 0");
	fputs(string, fileSETTINGS);
	fclose(fileSETTINGS);

}





void transf(int entree[16], int sortie[4][4], int n)// On charge le tableau de sauvegarde dans le tableau de jeuu en fonction de la taille
{

	switch (n)
	{
	case 4: // On coupe le tableau de sauvegarde en 4 et on rentre les valeurs ligne par ligne dans le tableau
		for (int u = 0; u < 4; u++)
		{
			sortie[0][u] = entree[u];
		}
		for (int yu = 4; yu < 8; yu++)
		{
			sortie[1][yu - 4] = entree[yu];

		}
		for (int cont = 8; cont < 12; cont++)
		{
			sortie[2][cont - 8] = entree[cont];
		}
		for (int ye = 12; ye < 16; ye++)
		{
			sortie[3][ye - 12] = entree[ye];
		}
		break;
	case 5://idem
		for (int u = 0; u < 5; u++)
		{
			sortie[0][u] = entree[u];
		}
		for (int yu = 5; yu < 10; yu++)
		{
			sortie[1][yu - 5] = entree[yu];

		}
		for (int cont = 10; cont < 15; cont++)
		{
			sortie[2][cont - 10] = entree[cont];
		}
		for (int ye = 15; ye < 20; ye++)
		{
			sortie[3][ye - 15] = entree[ye];
		}
		for (int i = 20; i < 25; i++)
		{
			sortie[4][i - 20] = entree[i];
		}
		break;
	case 6://idem
		for (int u = 0; u < 6; u++)
		{
			sortie[0][u] = entree[u];
		}
		for (int yu = 6; yu < 12; yu++)
		{
			sortie[1][yu - 6] = entree[yu];

		}
		for (int cont = 12; cont < 18; cont++)
		{
			sortie[2][cont - 12] = entree[cont];
		}
		for (int ye = 18; ye < 34; ye++)
		{
			sortie[3][ye - 18] = entree[ye];
		}
		for (int i = 24; i < 30; i++)
		{
			sortie[4][i - 24] = entree[i];
		}
		for (int i = 30; i < 36; i++)
		{
			sortie[5][i - 30] = entree[i];
		}
	}
	

	return sortie;
	
}



int afficherMENUfin(int cont, int tab[][4], struct cooscore cooa, SDL_Rect rectscore, int n)
{

	if (cont == 1) {
		return 1;  // le jeu continue
	}

	if (cont == 0 || cont == 2)
	{
		SDL_Surface* surfaceREJOUER = NULL;
		SDL_Surface* surfaceQUITTER = NULL;

		surfaceREJOUER = SDL_LoadBMP("2048PICTURES/fin1.bmp");
		surfaceQUITTER = SDL_LoadBMP("2048PICTURES/fin2.bmp");

		SDL_Rect RectFOND;
		RectFOND.x = 130;
		RectFOND.y = 120;
		RectFOND.w = 358;
		RectFOND.h = 295;

		int tabFIN[2];
		tabFIN[0] = 1;
		tabFIN[1] = 0;

		int menuFIN = 1;
		SDL_Event eventFIN;

		while (menuFIN)
		{
			SDL_UpdateWindowSurface(fenetre);

			SDL_WaitEvent(&eventFIN);
			switch (eventFIN.key.keysym.sym)
			{
			case(SDLK_RIGHT):
				if (tabFIN[1] != 1)
				{
					SDL_BlitSurface(surfaceQUITTER,NULL,surfacef , &RectFOND);
					AscoreFINAL(cont,cooa,rectscore);
					tabFIN[0] = 0;
					tabFIN[1] = 1;
				}

				break;

			case(SDLK_LEFT):
				if (tabFIN[0] != 1)
				{
					SDL_BlitSurface(surfaceREJOUER,NULL,surfacef , &RectFOND);
					AscoreFINAL(cont,cooa,rectscore);
					tabFIN[1] = 0;
					tabFIN[0] = 1;
				}

				break;
			case(SDLK_RETURN):

				if (tabFIN[0] == 1)
				{
					reset(tab, n);
					return 1;
					menuFIN = 0;
				}

				if (tabFIN[1] == 1)
				{
					return  0;
					menuFIN = 0;

				}
			}
			printf("\n");
			printf("%d\n", tabFIN[0]);
			printf("%d\n", tabFIN[1]);

		}
	}
}
void AscoreFINAL(int cont,struct cooscore cooa, SDL_Rect rectscore)  // permet d'afficher le score sur le menu de fin
{
		SDL_Surface* texte = NULL;
		TTF_Font* police = NULL;

		SDL_Color couleurBlanche = { 255, 255, 255 };	
		police = TTF_OpenFont("police_score.ttf", 33);		// on met la police au format ttf(SDL_tff) dans une variable

		char annoncefin[100] = "oui";						//tableau initialisé pour la phrase de fin

		rectscore.x = 265;
		rectscore.y = 235;

		if (cont == 0)									//si le joueur  gagne			
		{
			char finstring[100] = "Vous avez perdu !:";			//phrase de victoire
			sprintf(annoncefin, "%s", finstring);				//on met cette phrase dans le tableau précédent
			printf("%d", cooa.score);
			affscore(cooa.score,rectscore);						//affichage du score

		}
		else if (cont == 2)								//même chose si on perd
		{
			char finstring[100] = "Vous avez gagné !:";
			sprintf(annoncefin, "%s", finstring);
			affscore(cooa.score,rectscore);	
		}

		texte = TTF_RenderText_Solid(police, annoncefin, couleurBlanche);	//on charge notre texte 
		SDL_Rect recttext;

		recttext.x = 160;
		recttext.y = 150;

		SDL_BlitSurface(texte, NULL, surfacef, &recttext);					//on affichage le texte		

		SDL_UpdateWindowSurface(fenetre);									
}
