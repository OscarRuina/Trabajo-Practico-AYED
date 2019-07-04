#ifndef COMANDA_H
#define COMANDA_H
#include <SDL.h>

struct Comanda{
    int cantidadCarbon;
    int cantidadBronce;
    int cantidadPlata;
    int cantidadOro;
    int cantidadPlatino;

	SDL_Texture *imagen;
    SDL_Rect rectImg;
};


void crearComanda(Comanda &comanda);
void eliminarComanda(Comanda &comanda);
void dibujarGanadoComanda(Comanda &comanda);
void dibujarGameOverComanda(Comanda &comanda);
void mostrarComanda(Comanda &comanda);

int getCantidadCarbon(Comanda &comanda);
int getCantidadBronce(Comanda &comanda);
int getCantidadPlata(Comanda &comanda);
int getCantidadOro(Comanda &comanda);
int getCantidadPlatino(Comanda &comanda);

void setCantidadCarbon(Comanda &comanda,int cantidad);
void setCantidadBronce(Comanda &comanda,int cantidad);
void setCantidadPlata(Comanda &comanda,int cantidad);
void setCantidadOro(Comanda &comanda,int cantidad);
void setCantidadPlatino(Comanda &comanda,int cantidad);



#endif // COMANDA_H
