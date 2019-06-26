#ifndef Tren_h
#define Tren_h
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TiposMinerales.h"

/*TDA tren
definicion de tipo de dato para manejo de tren
Atributos:
 char tipo[3] ---> tipo de imagen c1 = tren
 int f ---> fila,coordenada de y
 int c ---> columna,coordenada de x
 char direccion[4] ---> direccion de la imagen,der,izq,aba,arr
 int anchoCasillero ---> ancho de la imagen
 int altoCasillero ---> alto imagen
 int altoSprite ---> alto del sprite
 *imagen ---> puntero a imagen
 rectImagen ---> variable para dibujar la imagen
*/

using namespace std;

typedef struct posicionAnterior{
    char direccionAnterior[4];
    int filaAnterior;
    int columnaAnterior;
};

typedef struct{
    char tipo[3];
    int f;
    int c;
    int monedas;
    char direccion[4];
    int kilos;

    posicionAnterior anterior;

    int cicloRender;
    int ciclo;
    bool seguir;
    TiposMinerales tipoMineral;

	SDL_Texture *imagen;
    SDL_Rect rectImag;
}Tren;
/*----------------------------------*/
/*
PRE: ventana creada con crear y tren no habe sido creado
POST: tren creado con crearTren
tren instancia sobre la cual actua la primitiva
char tipo: c1 tren
f: valor de la fila
c: valor de la columna
anchoCasillero: valor ancho de la imagen
altoCasillero: valor alto de la imagen
altoSprite: valor del sprite
*renderer: puntero del TDA ventana de tipo renderer
*/
void crearTren(Tren &tren,char tipo[],char  direccion[],int fil,int col,int kilos);
/*----------------------------------*/
/*
PRE:tren creado con crear
POST: devuelve el valor fila
tren instancia sobre la cual actua la primitiva
*/
int getFila(Tren &tren);
/*----------------------------------*/
/*
PRE:tren creado con crear
POST: devuelve el valor columna
tren instancia sobre la cual actua la primitiva
*/
int getColumna(Tren &tren);
/*----------------------------------*/
/*
PRE:tren creado con crear
POST:setea la fila con el valor desplazamiento
tren instancia sobre la cual actuala primitiva
desplazamiento valor para desplazarse por el mapa
*/
void setFila(Tren &tren,int desplazamiento);
/*----------------------------------*/
/*
PRE:tren creado con crear
POST:setea la columna con el valor desplazamiento
tren instancia sobre la cual actua la primitiva
desplazamiento valor para desplazarse por el mapa
*/
void setColumna(Tren &tren,int desplazamiento);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: tren dibujado en la ventana
tren instancia sobre la que actua la primitiva
renderer puntero del render en ventana
intervalo
*/
void dibujarTren(Tren &tren,SDL_Renderer* renderer);
/*----------------------------------
PRE: tren creado con crear
POST: tren mueve de posicion
tren instancia sobre la que actua la primitiva
renderer puntero del render en ventana
intervalo
*/
void moverTren(Tren &tren, int desplazamientoHorizontal,int desplazamientoVertical);
/*----------------------------------*/
bool verificarTipo(Tren &tren,char[]);
bool verificarDireccion(Tren &tren,char direc[]);
/*
PRE: tren creado con crear
POST: tren borrado de la ventana
tren instancia sobre la cual actua la primitiva
*/

void destruirTren(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato direccion
tren instancia sobre la cual actua la primitiva
*/
char* getDireccion(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea la direcion con el valor ingresado
tren instancia sobre la cual actua la primitiva
char direccion nuevo valor a setear
*/
void setDireccion(Tren &tren,char direccion[]);
/*----------------------------------*/

bool compararTren(Tren &tren,Tren &tren2);


void setCiclo(Tren &tren,int ciclo);
int getCiclo(Tren &tren);

void setCicloRender(Tren &tren,int ciclo);
int getCicloRender(Tren &tren);

void setDireccionAnterior(Tren &tren, char direccionAnterior[]);
char* getDireccionAnterior(Tren &tren);


void setPosicionAnterior(Tren &tren,posicionAnterior anterior);
posicionAnterior getPosicionAnterior(Tren &tren);

int getMonedas(Tren &tren);
void setMonedas(Tren &tren,int monedas);


int getKilos(Tren &tren);

void setKilos(Tren &tren,int kilos);

#endif // Tren_h