#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

void tableauDeCharATexture(int ligne, int colonne, char damier[ligne][colonne], SDL_Renderer *renderer, SDL_Texture *mapTexture[ligne][colonne]);
void textureDestinationInit(int ligne, int colonne, SDL_Rect mapTextureDestination[ligne][colonne], int reso);

#endif // DISPLAY_H_INCLUDED
