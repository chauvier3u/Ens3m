#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void tableauDeCharATexture(int ligne, int colonne, int *damier[ligne][colonne], SDL_Renderer *renderer, SDL_Texture *mapTexture[ligne][colonne])
{
    printf("%d\n", damier);
    int i,j;
    for (i=0; i<ligne; i++)
    {
        for (j=0; j<colonne; j++)
        printf("%c",damier[i][j]);
    }

    SDL_Surface *imageBomb = IMG_Load("./Assets/Textures/Bomb.png");
	SDL_Surface *imageGround = IMG_Load("./Assets/Textures/Ground.png");
	SDL_Surface *imageTeleporter = IMG_Load("./Assets/Textures/Teleporter.png");
	SDL_Surface *imageWall = IMG_Load("./Assets/Textures/Wall.png");

	for (int i=0; i<ligne; i++)
	{
        for (int j=0; j<colonne; j++)
		{
    		if(damier[i][j] == '#')
			{
                printf("Mur\n");
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageWall);
			}
			else if(damier[i][j] == ' ')
			{
                printf("Sol\n");
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageGround);
			}
			else if (damier[i][j] == 'o')
			{
                printf("Bombe\n");
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageBomb);
			}else
			{
                mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageBomb);
			}
		}
	}

	SDL_FreeSurface(imageBomb);
	SDL_FreeSurface(imageGround);
	SDL_FreeSurface(imageTeleporter);
	SDL_FreeSurface(imageWall);
}

void textureDestinationInit(int ligne, int colonne, SDL_Rect mapTextureDestination[ligne][colonne], int reso)
{
	for (int i=0; i<ligne; i++)
	{
		for (int j=0; j<colonne; j++)
		{
            mapTextureDestination[i][j].x=i*reso;
            mapTextureDestination[i][j].y=j*reso;
            mapTextureDestination[i][j].h=reso;
            mapTextureDestination[i][j].w=reso;
		}
	}
}
