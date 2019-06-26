#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H
#include <SDL.h>
#include "Lista.h"
#include "ManejoVentana.h"
#include "Mapa.h"

void renderListaTrenes(Lista &lista,SDL_Renderer *renderer);
void setListaDireccionTrenes(Lista &lista);
void setListaEstadoAnterior(Lista &lista);
void generarListaMonedas(Ventana &ventana,Lista &lista,Mapa &mapa);
void renderListaMonedas(Lista &lista,SDL_Renderer* renderer,bool turnoMoneda);



#endif // FUNCIONESLISTA_H
