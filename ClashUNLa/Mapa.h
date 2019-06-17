#ifndef MAPA_H
#define MAPA_H
#include <SDL.h>
#include "Bloque.h"


typedef struct{
    int ancho;
    int alto;
    int col;
    int fil;
    Bloque bloques[15][20];
    SDL_Rect destino;
    SDL_Texture* textura;

}Mapa;



void crearMapa(Mapa &mapa,SDL_Renderer *renderer);
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer);
void destruirMapa(Mapa &mapa);
void mostrarBloquesMapa(Mapa &mapa);
#endif // MAPA_H
