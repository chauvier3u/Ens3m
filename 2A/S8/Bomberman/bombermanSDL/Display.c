#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Display.h"

#define PATH_TO_TEXTURE "Assets/Textures/Pack1/"

void tableauDeCharATexture(int ligne, int colonne, char damier[ligne][colonne], SDL_Renderer *renderer, SDL_Texture *mapTexture[ligne][colonne])
{
	char PATH_TO_BOMB[100], PATH_TO_GROUND[100], PATH_TO_TELEPORTER[100], PATH_TO_WALL[100], PATH_TO_OBSTACLE[100], PATH_TO_HEROS[100];
    strcpy(PATH_TO_BOMB, PATH_TO_TEXTURE);
    strcpy(PATH_TO_GROUND, PATH_TO_TEXTURE);
    strcpy(PATH_TO_TELEPORTER, PATH_TO_TEXTURE);
    strcpy(PATH_TO_WALL, PATH_TO_TEXTURE);
    strcpy(PATH_TO_OBSTACLE, PATH_TO_TEXTURE);
    strcpy(PATH_TO_HEROS, PATH_TO_TEXTURE);

    strcat(PATH_TO_BOMB, "Bomb.png");
    strcat(PATH_TO_GROUND, "Ground.png");
    strcat(PATH_TO_TELEPORTER, "Teleporter.png");
    strcat(PATH_TO_WALL, "Wall.png");
    strcat(PATH_TO_OBSTACLE, "Obstacle.png");
    strcat(PATH_TO_HEROS, "Heros16px.png");

	SDL_Surface *imageBomb = IMG_Load(PATH_TO_BOMB);
	SDL_Surface *imageGround = IMG_Load(PATH_TO_GROUND);
	SDL_Surface *imageTeleporter = IMG_Load(PATH_TO_TELEPORTER);
	SDL_Surface *imageWall = IMG_Load(PATH_TO_WALL);
	SDL_Surface *imageObstacle = IMG_Load(PATH_TO_OBSTACLE);
	SDL_Surface *imageHeros = IMG_Load(PATH_TO_HEROS);

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
			else if (damier[i][j] == 'x')
			{
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageObstacle);
			}
			else if (damier[i][j] == 'B')
			{
				mapTexture[i][j] = SDL_CreateTextureFromSurface(renderer, imageHeros);
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

void obstacle(int nbObs, int ligne, int colonne, char damier[ligne][colonne])
{
    // Génération aléatoire des obstacles
    int compteur = 0;
    int x = 1;
    int y = 1;

    // initialisation de la fonction random
    srand(time(NULL));

    while (compteur < nbObs)
    {
        // On met des obstacles sur les cases vides
        while (damier[x][y]!=' ')
        {
            x = rand()%(ligne);
            y = rand()%(colonne-1);
        }
        damier[x][y]='x';
        compteur+=1;
    }
}

void actionJoueur(char input, bomberman *J1, int ligne, int colonne, char damier[ligne][colonne])
{
    // Deplacement ou pose de bombe
    switch(input)
    {
        // Vers le haut
        case 'z':
            if(J1->x-1>=0 && damier[J1->x-1][J1->y]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->x=J1->x-1;
                damier[J1->x][J1->y]='B';
            }
            break;
        // Vers le bas
        case 's':
            if(J1->x+1<ligne && damier[J1->x+1][J1->y]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->x=J1->x+1;
                damier[J1->x][J1->y]='B';
            }
            break;
        // Vers la gauche
        case 'q':
            // Case Teleporter
            if(J1->y==0 && damier[J1->x][23] == ' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=23;
                damier[J1->x][J1->y]='B';
            }
            // Cas normal
            else if(J1->y-1>=0 && damier[J1->x][J1->y-1]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=J1->y-1;
                damier[J1->x][J1->y]='B';
            }
            break;
        // Vers la droite
        case 'd':
            // Case teleporter
            if(J1->y==23 && damier[J1->x][0]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=0;
                damier[J1->x][J1->y]='B';
            }
            // Cas normal
            else if(J1->y+1<colonne-2 && damier[J1->x][J1->y+1]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=J1->y+1;
                damier[J1->x][J1->y]='B';
            }
            break;
        // Pose de bombe
        case ' ':
            if (J1->nombreBombeActive<NOMBRE_DE_BOMBE && damier[J1->x][J1->y] != 'o')
                {
                    damier[J1->x][J1->y] = 'o';
                    bombe *B1 = malloc(sizeof(bombe));
                    B1->tempsAvantExplosion=TEMPS_AVANT_EXPLOSION+1;
                    B1->rayonExplosion=RAYON_EXPLOSION;
                    B1->x=J1->x;
                    B1->y=J1->y;
                    J1->listeBombe[J1->nombreBombeActive]=B1;
                    J1->nombreBombeActive++;
                    J1->nombreBombesPose++;
                }
            break;
        default:
            break;
    }
}
