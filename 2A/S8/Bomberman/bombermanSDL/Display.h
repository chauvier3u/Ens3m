#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#define NOMBRE_DE_BOMBE 2       // On impose le nombre max de bombe par joueur
#define RAYON_EXPLOSION 2
#define TEMPS_AVANT_EXPLOSION 5

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
    int enVie;
    int nombreBombesPose;
    int nombreObstacleCasse;
    bombe *listeBombe[NOMBRE_DE_BOMBE];
}bomberman;

void tableauDeCharATexture(int ligne, int colonne, char damier[ligne][colonne], SDL_Renderer *renderer, SDL_Texture *mapTexture[ligne][colonne]);
void textureDestinationInit(int ligne, int colonne, SDL_Rect mapTextureDestination[ligne][colonne], int reso);

void obstacle(int nbObs, int ligne, int colonne, char damier[ligne][colonne]);
void actionJoueur(char input, bomberman *J1, int ligne, int colonne, char damier[ligne][colonne]);
#endif // DISPLAY_H_INCLUDED
