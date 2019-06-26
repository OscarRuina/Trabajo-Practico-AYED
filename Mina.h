#ifndef MINA_H
#define MINA_H
#include <SDL.h>
#include <SDL_image.h>
#include "TiposMinerales.h"

struct Mina{
    int ancho;
    int largo;
    int numeroCasillero;
    TiposMinerales tipo;
    int cajas[5];
    SDL_Rect destino;
    SDL_Texture *textura;
};

void crearMina(Mina &mina,SDL_Renderer *renderer);
void generarPosicion(Mina &mina);
void crearCajas(Mina &mina);
void eliminarMina(Mina &mina);
#endif // MINA_H
