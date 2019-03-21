#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void action(char input, int *x, int *y, int ligne, int colonne, char damier[ligne][colonne])
{
    switch(input)
    {
        case 'z':
            if(*x-1>=0 && damier[*x-1][*y]==' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *x=(*x)-1;
                damier[*x][*y]='B';
            }
            break;
        case 's':
            if((*x)+1<ligne && damier[(*x+1)][*y]==' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *x=*x+1;
                damier[*x][*y]='B';
            }
            break;
        case 'q':
            if(*y==0 && damier[*x][23] == ' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *y=23;
                damier[*x][*y]='B';
            }else if((*y)-1>=0 && damier[*x][*y-1]==' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *y=*y-1;
                damier[*x][*y]='B';
            }
            break;
        case 'd':
            if(*y==23 && damier[*x][0]==' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *y=0;
                damier[*x][*y]='B';
            }else if((*y)+1<colonne-2 && damier[*x][*y+1]==' ')
            {
                if(damier[*x][*y]!='o')
                {
                    damier[*x][*y] = ' ';
                }
                *y=*y+1;
                damier[*x][*y]='B';
            }
            break;
        case ' ':
            damier[*x][*y] = 'o';
            break;
        default:
            break;
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
