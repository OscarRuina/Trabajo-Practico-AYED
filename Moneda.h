#ifndef MONEDA_H
#define MONEDA_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    int posX;
    int posY;
    int vidaUtil;
    SDL_Rect destino;
    SDL_Texture *textura;

}Moneda;

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer);
void dibujarMoneda(Moneda &moneda,SDL_Renderer* renderer);
void destruirMoneda(Moneda &moneda);
int generarNumeroRandom();
#endif // MONEDA_H
