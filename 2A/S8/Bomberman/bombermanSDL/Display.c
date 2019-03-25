#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.h"

void tableauDeCharATexture(int ligne, int colonne, char damier[ligne][colonne], SDL_Renderer *renderer, SDL_Texture *mapTexture[ligne][colonne])
{
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
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageWall);
			}
			else if(damier[i][j] == ' ')
			{
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageGround);
			}
			else if (damier[i][j] == 'o')
			{
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageBomb);
			}
			else
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
			mapTextureDestination[i][j].x=j*reso;
			mapTextureDestination[i][j].y=i*reso;
			mapTextureDestination[i][j].h=reso;
			mapTextureDestination[i][j].w=reso;
		}
	}
}
