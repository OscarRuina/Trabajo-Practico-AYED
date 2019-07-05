#ifndef MINA_H
#define MINA_H
#include <SDL.h>
#include <SDL_image.h>
#include "TiposMinerales.h"
/*Definicion del tipo de datos para el manejo de Mina*/
/*
Atributos:
fila: fila
col: columna
tipo: minerales a producir
cajas: array de cajas
rectImg: variable de tipo SDL_Rect
imagen:puntero de tipo SDL_Texture
*/
/*Estructura de tipo mina*/
struct Mina{
    int fil;
    int col;
    TiposMinerales tipo;
    int cicloEntrega;

    int cicloIntervalo;
    int intervalo;
    int cajasDisponibles;
    int cajas[5] ={2,2,4,3,5};
    SDL_Rect rectImg;
    SDL_Texture *imagen;
};
/*------------------------------*/
/*
PRE: mina no debe haber sido creada
POST: mina creada
mina:instancia sobre la que actua la primitiva
renderer:puntero de tipo renderer
tipo: tipo de mineral
*/
void crearMina(Mina &mina,SDL_Renderer *renderer,int fil,int col,int tipo,int intervalo);
/*------------------------------*/
/*
PRE: mina debe haber sido creada
POST: caja entregada
mina: instancia sobre la que actua la primitiva
*/
int entregarCaja(Mina &mina);
/*------------------------------*/
/*
PRE: mina debe haber sido creada
POST: mina eliminada
mina: instancia sobre la que actua la primitiva
*/
void eliminarMina(Mina &mina);
/*------------------------------*/
/*
PRE: mina debe haber sido creada
POST: mina dibujada en el mapa
mina: instancia sobre la que actua la primitiva
*/
void dibujarMina(Mina &mina,SDL_Renderer *renderer);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: retorna el ciclo de entrega
mina: instancia sobre la que actua la primitiva
*/
int getCicloEntrega(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: setea el ciclo de entrega
mina: instancia sobre la que actua la primitiva
ciclo: valor a setear
*/
void setCicloEntrega(Mina &mina, int ciclo);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: cajas de la mina reseteadas
mina: instancia sobre la que actua la primitiva
*/
void resetearCajasMina(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: setea el tipo mineral
mina: instancia sobre la que actua la primitiva
tipo: valor a setear
*/
void setTipoMineral(Mina &mina,TiposMinerales tipo);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: retorna el tipo mineral
mina: instancia sobre la que actua la primitiva
*/
TiposMinerales getTipoMineral(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: muestra el tipo mineral de la mina
mina: instancia sobre la que actua la primitiva
*/
void mostrarTipoMina(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: setea el intervalo
mina: instancia sobre la que actua la primitiva
intervalo: valor a setear
*/
void setIntervalo(Mina &mina,int intervalo);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: retorna el intervalo
mina: instancia sobre la que actua la primitiva
*/
int getIntervalo(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: setea el ciclo del intervalo
mina: instancia sobre la que actua la primitiva
intervalo: valor a setear
*/
void setCicloIntervalo(Mina &mina,int intervalo);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: retorna el ciclo del intervalo
mina: instancia sobre la que actua la primitiva
*/
int getCicloIntervalo(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: setea las cajas
mina: instancia sobre la que actua la primitiva
cajasdisponibles: valor a setear
*/
void setCajasDisponibles(Mina &mina,int cajasDisponibles);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: retorna el vallor de las cajas
mina: instancia sobre la que actua la primitiva
*/
int getCajasDisponibles(Mina &mina);
/*-------------------------*/
/*
PRE: mina debe haber sido creada
POST: actualiza la mina
mina: instancia sobre la que actua la primitiva
*/
void updateMina(Mina &mina);
#endif // MINA_H
