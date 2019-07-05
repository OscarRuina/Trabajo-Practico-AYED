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
 int monedas ---> numero de monedas
 int kilos ---> numero de kilos
 int altoSprite ---> alto del sprite
 *imagen ---> puntero a imagen
 rectImagen ---> variable para dibujar la imagen
*/

using namespace std;
/* tipo de dato para saber la posicion del tren*/
struct posicionAnterior{
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
    int kilosOcupados;

    posicionAnterior anterior;

    int ciclo;

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
void moverTren(Tren &tren, int velX,int velY);
/*----------------------------------*/
bool verificarTipo(Tren &tren,char[]);
/*----------------------------------*/
bool verificarDireccion(Tren &tren,char direc[]);
/*----------------------------------*/
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
/*
PRE: tren creado con crear
POST: compara dos trenes
tren instancia sobre la cual actua la primitiva
*/
bool compararTren(Tren &tren,Tren &tren2);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea el atributo ciclo
tren instancia sobre la cual actua la primitiva
ciclo: atributo a setear
*/
void setCiclo(Tren &tren,int ciclo);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato ciclo
tren instancia sobre la cual actua la primitiva
*/
int getCiclo(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea el dato direccion anterior
tren instancia sobre la cual actua la primitiva
direccionAnterior: dato a setear
*/
void setDireccionAnterior(Tren &tren, char direccionAnterior[]);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato direccion anterior
tren instancia sobre la cual actua la primitiva
*/
char* getDireccionAnterior(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea el dato posicion anterior
tren instancia sobre la cual actua la primitiva
anterior: estructura a setear
*/
void setPosicionAnterior(Tren &tren,posicionAnterior anterior);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato posicion anterior
tren instancia sobre la cual actua la primitiva
*/
posicionAnterior getPosicionAnterior(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato moneda
tren instancia sobre la cual actua la primitiva
*/
int getMonedas(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea el dato moneda
tren instancia sobre la cual actua la primitiva
monedas: dato a setear
*/
void setMonedas(Tren &tren,int monedas);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato kilos
tren instancia sobre la cual actua la primitiva
*/
int getKilos(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: seteado el dato kilos
tren instancia sobre la cual actua la primitiva
kilos: dato a setear
*/
void setKilos(Tren &tren,int kilos);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: seteado el ciclo cambio
tren instancia sobre la cual actua la primitiva
cicloCambioFC: dato a setear
*/
void setCicloCambioFC(Tren &tren,int cicloCambioFC);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: devuelve el dato ciclo cambio
tren instancia sobre la cual actua la primitiva
*/
int getCicloCambioFC(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: modifica la fila y columna
tren instancia sobre la cual actua la primitiva
*/
void cambiarFilaColumna(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: muestra el ciclo de cambio
tren instancia sobre la cual actua la primitiva
*/
void mostrarTrenFC(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: true si las fila y columna son iguales,false sino lo son
tren instancia sobre la cual actua la primitiva
*/
bool compararFilaColumna(Tren &este,Tren &otro);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: retorna los kilos
tren instancia sobre la cual actua la primitiva
*/
int getKilosOcupados(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea los kilos
tren instancia sobre la cual actua la primitiva
kilos: valor a setear
*/
void setKilosOcupados(Tren &tren,int kilos);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: retorna los tipos minerales
tren instancia sobre la cual actua la primitiva
*/
TiposMinerales getTipoMineral(Tren &tren);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: setea el tipo mineral
tren instancia sobre la cual actua la primitiva
tipo: valor a setear
*/
void setTipoMineral(Tren &tren,TiposMinerales tipo);
/*----------------------------------*/
/*
PRE: tren creado con crear
POST: muestra los kilos
tren instancia sobre la cual actua la primitiva
*/
void mostrarKilos(Tren &tren);
#endif // Tren_h
