#ifndef Estacion_h
#define Estacion_h
#include <SDL.h>
#include <SDL_image.h>
/*Definicion del tipo de dato para manejo de estacion*/
/*
Atributos:

 int f ---> fila,coordenada de y
 int c ---> columna,coordenada de x
 int anchoCasillero ---> ancho de la imagen
 int altoCasillero ---> alto imagen
 *imagen ---> puntero a imagen
 rectImagen ---> variable para dibujar la imagen
*/
/*Tipo de estructura de la estacion*/
typedef struct{
  int f;
  int c;
  SDL_Texture *imagen;
  SDL_Rect rectImagen;
}Estacion;
/*----------------------------*/
/*
PRE: ventana creada con crear, estacion no creada
POST:estacion creada con crear
estacion: instancia sobre la cual se invoca la primitiva
f: valor de la fila
c: valor de la columna
anchoCasillero: valor ancho de la imagen
altoCasillero: valor alto de la imagen
*renderer: puntero del TDA ventana de tipo renderer
*/
void crearEstacion(Estacion &estacion,SDL_Renderer *renderer);
/*----------------------------*/
/*
PRE: estacion creada con crear
POST: estacion dibujada en la ventana
estacion: instancia sobre la cual se invoca la primitiva
*renderer: puntero del TDA ventana de tipo renderer
*/
void dibujarEstacion(Estacion &estacion,SDL_Renderer *renderer);
/*----------------------------*/
/*
PRE: estacion creada con crear
POST: estacion borrada de la ventana
estacion: instancia sobre la cual se invoca la primitiva
*/
void destruirEstacion(Estacion &estacion);
/*----------------------------*/
void cargarVariables(Estacion &estacion);

void setFila(Estacion &estacion,int fil);

int getFila(Estacion &estacion);


void setColumna(Estacion &estacion,int col);

int getColumna(Estacion &estacion);
#endif
