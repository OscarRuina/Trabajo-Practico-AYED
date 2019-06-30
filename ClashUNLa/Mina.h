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
    int cajas[5];
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
void crearMina(Mina &mina,SDL_Renderer *renderer,int tipo);
/*------------------------------*/
/*
PRE: mina debe haber sido creada
POST: caja creada
mina: instancia sobre la que actua la primitiva
*/
void cargarCajas(Mina &mina);
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
#endif // MINA_H
