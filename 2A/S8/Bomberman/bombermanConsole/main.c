#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilitaire.h"

#define NOMBRE_OBSTACLE 15

int main()
{
    // Liste des maps, c'est assez explicite
    char listeDesMaps[2][100] = {"ensem", "bomberman"};


    // Ouverture et stocakge de la map dans le damier
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
    J1->nombreBombeActive=0;


    // Initialisation du damier
    damier[J1->x][J1->y]='B';
    obstacle(NOMBRE_OBSTACLE, ligne, colonne, damier);


    // Affichage du damier
    affiche(ligne, colonne, damier);


    // Initialisation de variable utile pour la boucle
    int jouer = 1;
    char touche='\n';


    // Boucle de jeu
    while (jouer)
    {
        // Action (déplacement / Poser Bombe)
        printf("dans quelle direction se deplacer (ou bien poser une bombe) ?\n");
        scanf("%c",&touche);
        printf("x:%d, y:%d\n",J1->x,J1->y);


        // Action en fonction de la touche jouer
        action(touche, J1, ligne, colonne, damier);
        affiche(ligne, colonne, damier);


        // On vide le buffer de stdin pour ne pas avoir de \n ni meme un autre caractère que l'utilisateur pourrait avoir rentré.
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }
   return 0;
}
