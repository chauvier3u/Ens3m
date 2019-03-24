#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.h"

#define RESOLUTION 32

const int SCREEN_WIDTH = (RESOLUTION * 24);
const int SCREEN_HEIGHT = (RESOLUTION * 16);


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

	// Initialisation de la SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Création d'une fentre
	SDL_Window *fenetre = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	// Création du contenu de la fenetre
	SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// Couleur Bleu jolie
	SDL_SetRenderDrawColor(renderer, 15, 157, 232, 0);

	IMG_Init(IMG_INIT_PNG);

	SDL_Texture *mapTexture[ligne][colonne];

    int i,j;
    for (i=0; i<ligne; i++)
    {
        for (j=0; j<colonne; j++)
        printf("%c",damier[i][j]);
    }
    printf("%d\n", &damier);

    tableauDeCharATexture(ligne, colonne, &damier, &renderer, &mapTexture);

	SDL_Rect mapTextureDestination[ligne][colonne];
	textureDestinationInit(ligne, colonne, mapTextureDestination, RESOLUTION);

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
		}
		// Clear
		SDL_RenderClear(renderer);

		// Dessine
		//SDL_RenderCopy(renderer, mapTexture[0][0], NULL, &(mapTextureDestination[0][0]));
        SDL_Delay(1000);
        /*for (int i=0;i<ligne;i++)
		{
            for (int j=0; j<colonne; j++)
            {
                SDL_RenderCopy(renderer, mapTexture[i][j], NULL, &mapTextureDestination[i][j]);
            }
		}*/

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
