#ifndef MONEDA_H
#define MONEDA_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

typedef struct
{
    int fil;
    int col;
    int vidaUtil;
    bool activa;
    SDL_Rect rectImg;
    SDL_Texture *textura;

}Moneda;

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer);
void dibujarMoneda(Moneda &moneda,SDL_Renderer* renderer,bool turno);
void destruirMoneda(Moneda &moneda);
int generarNumeroRandom(int minimo,int maximo);
#endif // MONEDA_H
