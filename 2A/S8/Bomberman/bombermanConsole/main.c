#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilitaire.h"

#define NOMBRE_OBSTACLE 25

int main()
{
    // Liste des maps, c'est assez explicite
    char listeDesMaps[2][100] = {"ensem", "bomberman"};


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



    // Initialisation du "booleen" et de l'input
    int jouer = 1;
    char input='\n';

    float score;

    // Boucle de jeu
    while (J1->enVie)
    {
        // Affichage du damier
        affiche(ligne, colonne, damier);

        // Action (déplacement / Poser Bombe)
        printf("dans quelle direction se deplacer (ou bien poser une bombe) ?\n");
        scanf("%c",&input);
        printf("x:%d, y:%d\n",J1->x,J1->y);


        // Action en fonction de la touche jouer
        actionJoueur(input, J1, ligne, colonne, damier);
        actionBombe(J1, ligne, colonne, damier);

        /*// Affichage de test
        if (J1->nombreObstacleCasse==0)
        {
            score = 0;
        }else
        {
            score = (float)J1->nombreObstacleCasse/(J1->nombreBombesPose*RAYON_EXPLOSION);
        }
        printf("Score du joueur :\nnombre de mur cassé / (nombre de bombe * rayon explosion)\n= %d / (%d * %d) = %f\n",
        J1->nombreObstacleCasse, J1->nombreBombesPose, RAYON_EXPLOSION, score);
*/

        // On vide le buffer de stdin pour ne pas avoir de \n ni meme un autre caractère que l'utilisateur pourrait avoir rentré.
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }
    printf("\n\nPartie TERMINEE");
   return 0;
}
