#ifndef MAPA_H
#define MAPA_H
#include <SDL.h>
#include "Bloque.h"
#include "Tren.h"
#include "ManejoVentana.h"
#include "Lista.h"
/*Definicion del tipo de datos para el manejo del mapa*/
/*
Atributos:
ancho: ancho de lmapa
alto: alto del mapa
col: columna
fil: fila
bloques: matriz de tipo bloque
destino: variable de tipo SDL_Rect
textura: puntero de tipo SDL_Texture
*/
/*Tipo de estructura de tipo mapa*/
typedef struct{
    int ancho;
    int alto;
    int col;
    int fil;
    Bloque bloques[15][20];
    SDL_Rect destino;
    SDL_Texture* textura;

}Mapa;
/*-------------------------------*/
/*
PRE: mapa no debe haber sido creado
POST: mapa creado
mapa:instancia sobre la que actua la primitiva
renderer: puntero de tipo renderer
*/
void crearMapa(Mapa &mapa,SDL_Renderer *renderer);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: mapa dibujado
mapa:instancia sobre la que actua la primitiva
renderer: puntero de tipo renderer
*/
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: mapa eliminado
mapa:instancia sobre la que actua la primitiva
*/
void destruirMapa(Mapa &mapa);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: muestra los bloques por pantalla
mapa:instancia sobre la que actua la primitiva
*/
void mostrarBloquesMapa(Mapa &mapa);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: colisiones evaluadas
mapa:instancia sobre la que actua la primitiva
ventana,lista,tren: instancias sobre la que actua la primitiva
*/
void evaluarColiciones(Lista &lista,Ventana &ventana,Mapa &mapa, Tren &tren);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: limites evaluados
mapa,ventana,tren:instancias sobre la que actua la primitiva
*/
void evaluarLimites(Ventana &ventana,Mapa &mapa,Tren &tren);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: evalua el grid
mapa,lista,ventana,tren:instancias sobre la que actua la primitiva
*/
void evaluarGrid(Lista &lista,Ventana &ventana,Mapa &mapa,Tren &tren);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: evalua la colision del tren con la estacion
tren,lista:instancias sobre la que actua la primitiva
*/
void colisionEstacion(Lista &lista,Tren &tren);
/*-------------------------------*/
/*
PRE: mapa  debe haber sido creado
POST: evalua la colision del tren con la moneda
lista,tren,bloque:instancias sobre la que actua la primitiva
*/
void colisionMoneda(Lista &lista,Tren &tren,Bloque &bloque);
#endif // MAPA_H
