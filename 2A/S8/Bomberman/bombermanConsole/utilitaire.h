#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED

#define NOMBRE_DE_BOMBE 2   // On impose le nombre max de bombe par joueur

void affiche(int ligne, int colonne, char damier[ligne][colonne]);
void action(char input, int *x, int *y, int ligne, int colonne, char damier[ligne][colonne]);
void obstacle(int nbObs, int ligne, int colonne, char damier[ligne][colonne]);

typedef struct
{
    int x;
    int y;
    int rayonExplosion;
    int tempsAvantExplosion;
}bombe;

typedef struct
{
    int x;
    int y;
    bombe listeBombe[NOMBRE_DE_BOMBE];
}bomberman;
#endif // UTILITAIRE_H_INCLUDED
