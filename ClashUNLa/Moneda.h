#ifndef MONEDA_H
#define MONEDA_H
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
/*Definicion del tipo de datos para manejo de moneda*/
/*
Atributos:
fil: fila
col: columna
vidaUtil: vida de la moneda
activa: booleano para saber si aparece o desaparece
rectImg: variable de tipo SDL_Rect
textura: puntero de tipo SDL_Texture
*/
/*Estructura de tipo moneda*/
typedef struct
{
    int fil;
    int col;
    int vidaUtil;
    bool activa;
    SDL_Rect rectImg;
    SDL_Texture *textura;

}Moneda;
/*------------------------------*/
/*
PRE: moneda no debe haber sido creada
POST: moneda creada
moneda:instancia sobre la cual actua la primitiva
renderer:puntero de tipo SDL_Renderer
*/
void crearMoneda(Moneda &moneda,SDL_Renderer* renderer);
/*------------------------------*/
/*
PRE: moneda  debe haber sido creada
POST: moneda dibujada
moneda:instancia sobre la cual actua la primitiva
renderer:puntero de tipo SDL_Renderer
*/
void dibujarMoneda(Moneda &moneda,SDL_Renderer* renderer,bool turno);
/*------------------------------*/
/*
PRE: moneda  debe haber sido creada
POST: moneda destruida
moneda:instancia sobre la cual actua la primitiva
*/
void destruirMoneda(Moneda &moneda);
/*------------------------------*/
/*
PRE: moneda  debe haber sido creada
POST: devuelve un numero
minimo,maximo: valores minimo y maximo del numero a generar
*/
int generarNumeroRandom(int minimo,int maximo);
#endif // MONEDA_H
