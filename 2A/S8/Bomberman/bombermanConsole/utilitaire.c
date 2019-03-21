#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilitaire.h"

#define RAYON_EXPLOSION 1
#define TEMPS_AVANT_EXPLOSION 3

void affiche(int ligne, int colonne, char damier[ligne][colonne])
{
    int i;
    int j;
    for (i=0; i<ligne; i++)
    {
        for (j=0; j<colonne; j++)
        printf("%c",damier[i][j]);
    }
}

void action(char input, bomberman *J1, int ligne, int colonne, char damier[ligne][colonne])
{
    switch(input)
    {
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
        case 'q':
            if(J1->y==0 && damier[J1->x][23] == ' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=23;
                damier[J1->x][J1->y]='B';
            }else if(J1->y-1>=0 && damier[J1->x][J1->y-1]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=J1->y-1;
                damier[J1->x][J1->y]='B';
            }
            break;
        case 'd':
            if(J1->y==23 && damier[J1->x][0]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=0;
                damier[J1->x][J1->y]='B';
            }else if(J1->y+1<colonne-2 && damier[J1->x][J1->y+1]==' ')
            {
                if(damier[J1->x][J1->y]!='o')
                {
                    damier[J1->x][J1->y] = ' ';
                }
                J1->y=J1->y+1;
                damier[J1->x][J1->y]='B';
            }
            break;
        case ' ':
            if (J1->nombreBombeActive<NOMBRE_DE_BOMBE)
                {
                    damier[J1->x][J1->y] = 'o';
                    bombe *B1 = malloc(sizeof(bombe));
                    B1->tempsAvantExplosion=TEMPS_AVANT_EXPLOSION+1;
                    B1->rayonExplosion=RAYON_EXPLOSION;
                    B1->x=J1->x;
                    B1->y=J1->y;
                    J1->listeBombe[J1->nombreBombeActive]=B1;
                    J1->nombreBombeActive++;
                }
            break;
        default:
            break;

    }
    for (int i=0; i<J1->nombreBombeActive; i++)
    {
        J1->listeBombe[i]->tempsAvantExplosion--;
        if(J1->listeBombe[i]->tempsAvantExplosion==0)
        {
            explosion(ligne, colonne, damier, J1->listeBombe[i]);
        }
    }
}

void obstacle(int nbObs, int ligne, int colonne, char damier[ligne][colonne])
{

    int compteur = 0;
    int x = 1;
    int y = 1;

    srand(time(NULL));

    while (compteur < nbObs)
    {
        while (damier[x][y]!=' ')
        {
            x = rand()%(ligne);
            y = rand()%(colonne-1);
        }
        damier[x][y]='x';
        compteur+=1;
    }
}

void explosion(int ligne, int colonne, char damier[ligne][colonne], bombe *B)
{
    printf("youpi\n");
    // To complete
}
