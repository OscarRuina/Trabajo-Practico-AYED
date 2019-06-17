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
    Moneda *moneda;
    //Villano *villano;
    Estacion *estacion;
    Mina *mina;

};

Bloque crearBloque(int id,int fila,int columna);
void mostrarBloque(Bloque &bloque);
void eliminarBloque(Bloque &bloque);
void setMoneda();
void setVillano();
void setEstacion();
void setMina();
Moneda* getMoneda();
//Villano* getVillano();
Estacion* getEstacion();
Mina* getMina();


#endif // BLOQUES_H
