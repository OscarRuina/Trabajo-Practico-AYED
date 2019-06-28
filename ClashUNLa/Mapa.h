#ifndef MAPA_H
#define MAPA_H
#include <SDL.h>
#include "Bloque.h"
#include "Tren.h"
#include "ManejoVentana.h"
#include "Lista.h"

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
void evaluarColiciones(Lista &lista,Ventana &ventana,Mapa &mapa, Tren &tren);
void evaluarLimites(Ventana &ventana,Mapa &mapa,Tren &tren);
void evaluarGrid(Lista &lista,Ventana &ventana,Mapa &mapa,Tren &tren);
void colisionEstacion(Lista &lista,Tren &tren);
void colisionMoneda(Lista &lista,Tren &tren,Bloque &bloque);

#endif // MAPA_H
