#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilitaire.h"

#define RAYON_EXPLOSION 2
#define TEMPS_AVANT_EXPLOSION 5

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
                }
            break;
        default:
            break;

    }

    // A mettre dans une fonction à part
    for (int i=0; i<J1->nombreBombeActive; i++)
    {
        J1->listeBombe[i]->tempsAvantExplosion--;
        if(J1->listeBombe[i]->tempsAvantExplosion<=0)
        {
            damier[J1->listeBombe[i]->x][J1->listeBombe[i]->y]=' ';
            explosion(ligne, colonne, damier[ligne][colonne], J1->listeBombe[i]);
            J1->listeBombe[i]=NULL;
            for (int j=0; j<NOMBRE_DE_BOMBE-1; j++)
            {
                J1->listeBombe[j]=J1->listeBombe[j+1];
            }
            i--;
            J1->nombreBombeActive--;
        }
    }
    // Fin de ce qu'il faut bouger
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
    // Ajouter la casse des murs
}
