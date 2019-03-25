#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.h"

#define RESOLUTION 64
#define NOMBRE_OBSTACLE 25

int main(int argc, char* args[])
{
	// Ouverture du fichier et stocakge de la map dans le damier en char[][]
	char PATH_TO_MAP[100]=("./Map/");
	strcat(PATH_TO_MAP, "ensem");

	int ligne;
	int colonne;

	FILE* map = fopen(PATH_TO_MAP,"r");
	fscanf(map, "%d %d\n", &ligne, &colonne);
	char damier[ligne][colonne];
	for (int i=0; i<ligne; i++)
	{
		fgets(damier[i], colonne, map);
	}
	fclose(map);

	// Initialisation de la taille de la fenetre de jeu
    int SCREEN_WIDTH = (RESOLUTION * (colonne-2));
    int SCREEN_HEIGHT = (RESOLUTION * ligne);

	// Initialisation de la SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Création d'une fentre
	SDL_Window *fenetre = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	// Création du contenu de la fenetre
	SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	IMG_Init(IMG_INIT_PNG);

	SDL_Texture *mapTexture[ligne][colonne];

    // Initialisation des elements du jeu
        // Initialisation du personnage
    bomberman *J1=malloc(sizeof(bomberman));
    J1->x=4;
    J1->y=1;
    J1->enVie=1;
    J1->nombreBombesPose=0;
    J1->nombreObstacleCasse=0;
    J1->nombreBombeActive=0;
        // Initialisation du damier
    damier[J1->x][J1->y]='B';
    obstacle(NOMBRE_OBSTACLE, ligne, colonne, damier);

	int jouer =1;
	SDL_Event event;
	while(jouer)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				jouer = 0;
			}
			if(event.type == SDL_KEYDOWN)
			{
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        actionJoueur('q', J1, ligne, colonne, &damier);
                        break;
                    case SDLK_RIGHT:
                        actionJoueur('d', J1, ligne, colonne, &damier);
                        break;
                    case SDLK_UP:
                        actionJoueur('z', J1, ligne, colonne, &damier);
                        break;
                    case SDLK_DOWN:
                        actionJoueur('s', J1, ligne, colonne, &damier);
                        break;
                    case SDLK_SPACE:
                        actionJoueur(' ', J1, ligne, colonne, &damier);
                        break;
                }
			}
		}

        tableauDeCharATexture(ligne, colonne, &damier, renderer, &mapTexture);
        SDL_Rect mapTextureDestination[ligne][colonne];
        textureDestinationInit(ligne, colonne, mapTextureDestination, RESOLUTION);

		// Clear
		SDL_RenderClear(renderer);

		// Dessine
		//SDL_RenderCopy(renderer, mapTexture[0][0], NULL, &(mapTextureDestination[0][0]));
        for (int i=0;i<ligne;i++)
		{
            for (int j=0; j<colonne; j++)
            {
                SDL_RenderCopy(renderer, mapTexture[i][j], NULL, &mapTextureDestination[i][j]);
            }
		}

		// Affiche
		SDL_RenderPresent(renderer);
	}

    for (int i=0;i<ligne;i++)
    {
        for (int j=0; j<colonne; j++)
        {
            SDL_DestroyTexture(mapTexture[i][j]);
        }
    }
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();

	return 0;
}
