#ifndef Bandido_h
#define Bandido_h
#include <SDL.h>

/*Definicion del tipo de datos para el manejo de bandido*/
/*
Atributos:
f: fila
c: columna
imagen: puntero de SDL_Texture
rectImagen: SDL_Rect para menejo de rectangulos
*/
typedef struct{
  int f;
  int c;
  int intervaloBandido;
  int vidaBandido;
  bool activo;
  int tipo;
  int cicloBandido;
  SDL_Texture *imagen;
  SDL_Rect rectImg;
}Bandido;
/*-------------------------------*/
/*
PRE: bandido no debe haber sido creado
POST: bandido creado
bandido: instancia sobre la cual actua la primitiva
*/
void crearBandido(Bandido &bandido,SDL_Renderer *renderer);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: bandido dibujado en la pantalla
bandido: instancia sobre la cual actua la primitiva
*/
void dibujarBandido(Bandido &bandido,SDL_Renderer *renderer,bool turno);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: bandido borrado en la pantalla
bandido: instancia sobre la cual actua la primitiva
*/
void destruirBandido(Bandido &bandido);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: variable cargadas de bandido
bandido: instancia sobre la cual actua la primitiva
*/
void cargarVariablesBandido(Bandido &bandido);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: seteado la fila
bandido: instancia sobre la cual actua la primitiva
f: valor a setear
*/
void setFila(Bandido &bandido,int f);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: seteado la columna
bandido: instancia sobre la cual actua la primitiva
c: valor a setear
*/
void setColumna(Bandido &bandido,int c);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: retorna la fila
bandido: instancia sobre la cual actua la primitiva
*/
int getFila(Bandido &bandido);
/*-------------------------------*/
/*
PRE: bandido creado con crear
POST: retorna la columna
bandido: instancia sobre la cual actua la primitiva
*/
int getColumna(Bandido &bandido);


int getCicloBandido(Bandido &bandido);
void setCicloBandido(Bandido &bandido,int ciclo);
#endif // Bandido_h
