#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H
#include <SDL.h>
#include "Lista.h"
#include "ManejoVentana.h"
#include "Mapa.h"
#include "Comanda.h"

void mostrarKilosLista(Lista &lista);
//itera la lista , y luego llama a dibujartren
void renderListaTrenes(Lista &lista,SDL_Renderer *renderer);
//cambia la direccion de los vagones dependiendo la ultima direccion del anterior
void setListaDireccionTrenes(Lista &lista);
//guarda la ultima posicion de todos los vagones
void setListaEstadoAnterior(Lista &lista);
void mostrarDirecciones(Lista &lista);
//cambia el numero de columna y fila de las monedas
void setFCListaTrenes(Lista &lista);
//verifica que el vagon principal no choque con otro vagon
void verificarColisionVagones(Ventana &ventana,Lista &lista,Tren &tren);
void verificarCantidadDeMinerales(Lista &lista);



//verifica el estado de las monedas , si es falso , lo saca de la lista
void verificarEstadoListaMonedas(Lista &lista,Mapa &mapa);
void mostrarMonedas(Lista &lista);
//genera la lista de las monedas y los agrega al mapa
void generarListaMonedas(Ventana &ventana,Lista &lista,Mapa &mapa);
//itera la lista y luego llama a dibujar moneda
void renderListaMonedas(Lista &lista,SDL_Renderer* renderer,bool turnoMoneda);



void generarListaMinas(Ventana &ventana,Mapa &mapa,Lista &lista);
void renderListaMinas(Lista &lista,SDL_Renderer *renderer);
void mostrarMineralesLista(Lista &lista);
void updateListaMinas(Lista &lista);


int verificarCantidadDeMinerales(Lista &lista,TiposMinerales mineral);
bool verificarComanda(Lista &lista,Comanda &comanda);

void verificarEstadoListaBandidos(Lista &lista,Mapa &mapa);
void renderListaBandido(Lista &lista,SDL_Renderer* renderer,bool turno);
void generarListaBandidos(Ventana &ventana,Mapa &mapa,Lista &lista);
#endif // FUNCIONESLISTA_H
