#include "Bloque.h"
#include <iostream>
#ifndef NULL
#define NULL 0
#endif // NULL
using namespace std;

Bloque crearBloque(int id,int fil,int col){
    Bloque bloque;
    bloque.idBloque=id;
    bloque.fil=fil;
    bloque.col=col;
    bloque.estacion=NULL;
    bloque.mina=NULL;
    bloque.moneda=NULL;
    bloque.ocupado = false;
  //  bloque.villano=NULL;
  return bloque;
}

void setEstacion(Bloque &bloque,Estacion *estacion){
    bloque.estacion=estacion;
    bloque.ocupado = true;

}
void setMoneda(Bloque &bloque,Moneda *moneda){
    bloque.moneda=moneda;
    bloque.ocupado=true;
}

void mostrarBloque(Bloque &bloque){
    cout<<"Id: "<<bloque.idBloque<<endl;
    cout<<"Columna: "<<bloque.col<<endl;
    cout<<"Fila: "<<bloque.fil<<endl;

}

void setMina(Bloque &bloque, Mina *mina){
    bloque.mina=mina;
    bloque.ocupado=true;
}

void destruirBloque(Bloque &bloque){

}
void liberarBloque(Bloque &bloque){
    bloque.estacion=NULL;
    bloque.mina=NULL;
    bloque.moneda=NULL;
    bloque.ocupado = false;
}

