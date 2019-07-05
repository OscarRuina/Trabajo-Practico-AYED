#ifndef BLOQUE_H
#define BLOQUE_H
#include "Moneda.h"
#include "Estacion.h"
#include "Mina.h"
#include "Bandido.h"
/*Definicion del tipo de datos para menejo del bandido*/
/*
Atributos:
idBloque: id para identificar los bloques
fil: entero fila
col: entero columna
ocupado: booleano para saber si esta ocupado o no
moneda: puntero de tipo Moneda
estacion: puntero de tipo Estacion
mina: puntero de tipo Mina
*/
struct Bloque
{
    int idBloque;
    int fil;
    int col;
    bool ocupado;
    Moneda *moneda;
    Bandido *bandido;
    Estacion *estacion;
    Mina *mina;

};
/*--------------------------------*/
/*
PRE: bloque no debe haber sido creado
POST: bloque creado
id,fila,columna: atributos para crear el bloque
*/
Bloque crearBloque(int id,int fila,int columna);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: muestra el bloque
bloque: instancia sobre la actua la primitiva
*/
void mostrarBloque(Bloque &bloque);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: destruye el bloque
bloque: instancia sobre la actua la primitiva
*/
void destruirBloque(Bloque &bloque);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: seteada la moneda
bloque: instancia sobre la actua la primitiva
moneda: puntero de tipo moneda a setear
*/
void setMoneda(Bloque &bloque,Moneda *moneda);
/*--------------------------------*/
//void setBandido(Bloque &bloque,Bandido *villano);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: seteada la estacion
bloque: instancia sobre la actua la primitiva
estacion: puntero a setear
*/
void setEstacion(Bloque &bloque,Estacion *estacion);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: seteada la mina
bloque: instancia sobre la actua la primitiva
mina: puntero a setear
*/
void setMina(Bloque &bloque, Mina *mina);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: retorna la moneda
bloque: instancia sobre la actua la primitiva
*/
Moneda* getMoneda(Bloque &bloque);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: retorna la estacion
bloque: instancia sobre la actua la primitiva
*/
Estacion* getEstacion(Bloque &bloque);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST:
bloque: instancia sobre la actua la primitiva
*/
Mina* getMina(Bloque &bloque);
/*--------------------------------*/
/*
PRE: bloque debe haber sido creado
POST: bloque liberado
bloque: instancia sobre la actua la primitiva
*/
void liberarBloque(Bloque &bloque);
/*--------------------------------*/


Bandido* getBandido(Bloque &bloque);
void setBandido(Bloque &bloque,Bandido *bandido);
void liberarBloqueBandido(Bloque &bloque);
#endif // BLOQUES_H
