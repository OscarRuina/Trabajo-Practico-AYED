#ifndef BLOQUE_H
#define BLOQUE_H
#include "Moneda.h"
#include "Estacion.h"
#include "Mina.h"


struct Bloque
{
    int idBloque;
    int fil;
    int col;
    bool ocupado;
    Moneda *moneda;
    //Villano *villano;
    Estacion *estacion;
    Mina *mina;

};

Bloque crearBloque(int id,int fila,int columna);
void mostrarBloque(Bloque &bloque);
void destruirBloque(Bloque &bloque);
void setMoneda(Bloque &bloque,Moneda *moneda);
//void setVillano(Bloque &bloque,Villano *villano);
void setEstacion(Bloque &bloque,Estacion *estacion);
void setMina(Bloque &bloque, Mina &mina);
Moneda* getMoneda();
Estacion* getEstacion();
Mina* getMina();
void liberarBloque(Bloque &bloque);
//Villano* getVillano();

#endif // BLOQUES_H
