#ifndef CARAVANA_H
#define CARAVANA_H
#include "Tren.h"
struct NodoTren{
    Tren tren;
    NodoTren* siguiente;
    NodoTren* anterior;
};

typedef NodoTren* ptrTren;

struct Caravana{
    ptrTren primero;
    ptrTren ultimo;

};

ptrTren crearNodo(Tren tren);
void crearCaravana(Caravana &caravana);
void agregarNodo(Caravana &caravana);
void dibujarCaravana(Caravana &caravana);
void eliminarCaravana(Caravana &caravana);
void crearCaravana(Caravana &caravana);
void agregarPrimero(Caravana &caravana,NodoTren tren);
void agregarUltimo(Caravana &caravana,NodoTren tren);



#endif // CARAVANA_H
