#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED

#define NOMBRE_DE_BOMBE 2       // On impose le nombre max de bombe par joueur

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
    int nombreBombeActive;
    bombe *listeBombe[NOMBRE_DE_BOMBE];
}bomberman;

void affiche(int ligne, int colonne, char damier[ligne][colonne]);
void action(char input, bomberman *J1, int ligne, int colonne, char damier[ligne][colonne]);
void obstacle(int nbObs, int ligne, int colonne, char damier[ligne][colonne]);
#endif // UTILITAIRE_H_INCLUDED
