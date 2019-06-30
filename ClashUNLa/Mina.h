#ifndef MINA_H
#define MINA_H
#include <SDL.h>
#include <SDL_image.h>
#include "TiposMinerales.h"

struct Mina{
    int fil;
    int col;
    TiposMinerales tipo;
    int cajas[5];
    SDL_Rect rectImg;
    SDL_Texture *imagen;
};

void crearMina(Mina &mina,SDL_Renderer *renderer,int tipo);
void cargarCajas(Mina &mina);
void eliminarMina(Mina &mina);
void dibujarMina(Mina &mina,SDL_Renderer *renderer);
#endif // MINA_H
