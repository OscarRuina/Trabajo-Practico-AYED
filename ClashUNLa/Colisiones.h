#ifndef COLISIONES_H
#define COLISIONES_H
#include "Lista.h"
#include "Mapa.h"
#include "Tren.h"
#include "Moneda.h"
#include "Bandido.h"
#include "Bloque.h"


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

/*
PRE: mapa  debe haber sido creado
POST: evalua la colision del tren con las minas
tren,lista:instancias sobre la que actua la primitiva
*/
void colisionMina(Lista &lista,Tren &tren,Bloque &bloque);
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

void colisionBandido(Lista &lista,Tren &tren,Bloque &bloque );

#endif // COLISIONES_H
