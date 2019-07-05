#ifndef COMANDA_H
#define COMANDA_H
#include <SDL.h>
/*Tipo de datos para el manejo de comanda*/
/*
Atributos:
cantidadcarbon: cantidades
cantidadbronce: a
cantidadplata: obtener para
cantidadoro:   ganar el
cantidadplatino: juego
*/
/*estructura comanda*/
struct Comanda{
    int cantidadCarbon;
    int cantidadBronce;
    int cantidadPlata;
    int cantidadOro;
    int cantidadPlatino;

	SDL_Texture *imagen;
    SDL_Rect rectImg;
};
/*--------------------*/
/*
PRE: comanda no debe haber sido creada
POST: comanda creada
comanda: instancia sobre la que actua la primitiva
*/
void crearComanda(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda  debe haber sido creada
POST: comanda eliminada
comanda: instancia sobre la que actua la primitiva
*/
void eliminarComanda(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda  debe haber sido creada
POST: comanda dibujada ganador
comanda: instancia sobre la que actua la primitiva
*/
void dibujarGanadoComanda(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda  debe haber sido creada
POST: comanda dibujada juego terminado
comanda: instancia sobre la que actua la primitiva
*/
void dibujarGameOverComanda(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda  debe haber sido creada
POST: comanda aparece en pantalla
comanda: instancia sobre la que actua la primitiva
*/
void mostrarComanda(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: retorna la cantidad del carbon
comanda: instancia sobre la que actua la primitiva
*/
int getCantidadCarbon(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: retorna la cantidad del bronce
comanda: instancia sobre la que actua la primitiva
*/
int getCantidadBronce(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: retorna la cantidad de la plata
comanda: instancia sobre la que actua la primitiva
*/
int getCantidadPlata(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: retorna la cantidad del oro
comanda: instancia sobre la que actua la primitiva
*/
int getCantidadOro(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: retorna la cantidad del platino
comanda: instancia sobre la que actua la primitiva
*/
int getCantidadPlatino(Comanda &comanda);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: setea la cantidad de carbon
comanda: instancia sobre la cual actua la primitiva
cantidad: valor a setear
*/
void setCantidadCarbon(Comanda &comanda,int cantidad);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: setea la cantidad de bronce
comanda: instancia sobre la cual actua la primitiva
cantidad: valor a setear
*/
void setCantidadBronce(Comanda &comanda,int cantidad);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: setea la cantidad de plata
comanda: instancia sobre la cual actua la primitiva
cantidad: valor a setear
*/
void setCantidadPlata(Comanda &comanda,int cantidad);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: setea la cantidad de oro
comanda: instancia sobre la cual actua la primitiva
cantidad: valor a setear
*/
void setCantidadOro(Comanda &comanda,int cantidad);
/*--------------------*/
/*
PRE: comanda creada con crear
POST: setea la cantidad de platino
comanda: instancia sobre la cual actua la primitiva
cantidad: valor a setear
*/
void setCantidadPlatino(Comanda &comanda,int cantidad);
#endif // COMANDA_H
