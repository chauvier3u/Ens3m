#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utilitaire.h"

void affiche(int ligne, int colonne, char damier[ligne][colonne])
{
    // Affichage du damier
    int i;
    int j;
    for (i=0; i<ligne; i++)
    {
        for (j=0; j<colonne; j++)
        printf("%c",damier[i][j]);
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

// Reduction du temps avant explosion des bombes et eventuellement explosion
void actionBombe(bomberman *J1, int ligne, int colonne, char damier[ligne][colonne])
{
    for (int i=0; i<J1->nombreBombeActive; i++)
    {
        J1->listeBombe[i]->tempsAvantExplosion--;
        if(J1->listeBombe[i]->tempsAvantExplosion<=0)
        {
            damier[J1->listeBombe[i]->x][J1->listeBombe[i]->y]=' ';
            explosion(ligne, colonne, damier, J1->listeBombe[i], J1);
            J1->listeBombe[i]=NULL;
            for (int j=0; j<NOMBRE_DE_BOMBE-1; j++)
            {
                J1->listeBombe[j]=J1->listeBombe[j+1];
            }
            i--;
            J1->nombreBombeActive--;
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

void explosion(int ligne, int colonne, char damier[ligne][colonne], bombe *B, bomberman *J)
{
    int encoreEnHaut = B->rayonExplosion;
    int encoreAGauche = B->rayonExplosion;
    int encoreADroite = B->rayonExplosion;
    int encoreEnBas = B->rayonExplosion;

    int x = B->x;
    int y = B->y;

    for (int i=1; i<=B->rayonExplosion; i++)
    {
        // Explosion vers le haut
        if (encoreEnHaut>0)
        {
            encoreEnHaut--;

            // Si c'est le joueur, on perd
            if (damier[x-i][y] == 'B')
            {
                J->enVie=0;
            }

            // Si c'est un obstacle on le tue et explose pas plus loin
            if (damier[x-i][y] == 'x')
            {
                encoreEnHaut=0;
                damier[x-i][y]=' ';
                J->nombreObstacleCasse++;
            }

            // Si c'est un mur, on vérifie pas plus loin
            if (damier[x-i][y] == '#')
            {
                encoreEnHaut = 0;
            }
        }

        // Explosion vers le bas
        if (encoreEnBas>0)
        {
            encoreEnBas--;

            // Si c'est le joueur, on perd
            if (damier[x+i][y] == 'B')
            {
                J->enVie=0;
            }

            // Si c'est un obstacle on le tue et explose pas plus loin
            if (damier[x+i][y] == 'x')
            {
                encoreEnBas=0;
                damier[x+i][y]=' ';
                J->nombreObstacleCasse++;
            }

            // Si c'est un mur, on vérifie pas plus loin
            if (damier[x+i][y] == '#')
            {
                encoreEnBas = 0;
            }
        }

        // Explosion vers la gauche
        if (encoreAGauche>0)
        {
            encoreAGauche--;

            // Si c'est le joueur, on perd
            if (damier[x][y-i] == 'B')
            {
                J->enVie=0;
            }

            // Si c'est un obstacle on le tue et explose pas plus loin
            if (damier[x][y-i] == 'x')
            {
                encoreAGauche=0;
                damier[x][y-i]=' ';
                J->nombreObstacleCasse++;
            }

            // Si c'est un mur, on vérifie pas plus loin
            if (damier[x][y-i] == '#')
            {
                encoreAGauche= 0;
            }
        }

        // Explosion vers la droite
        if (encoreADroite>0)
        {
            encoreADroite--;

            // Si c'est le joueur, on perd
            if (damier[x][y+i] == 'B')
            {
                J->enVie=0;
            }

            // Si c'est un obstacle on le tue et explose pas plus loin
            if (damier[x][y+i] == 'x')
            {
                encoreADroite=0;
                damier[x][y+i]=' ';
                J->nombreObstacleCasse++;
            }

            // Si c'est un mur, on vérifie pas plus loin
            if (damier[x][y+i] == '#')
            {
                encoreADroite= 0;
            }
        }
    }
}
