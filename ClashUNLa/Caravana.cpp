#include "Caravana.h"
#ifndef NULL 0
#endif // NULL
ptrTren crearNodo(Tren tren){
    ptrTren nodo = new NodoTren();
    nodo->tren=tren;
    nodo->anterior=NULL;
    nodo->siguiente=NULL;
    return nodo;
}
void crearCaravana(Caravana &caravana){
    caravana.primero=NULL;
    caravana.ultimo=NULL;
}
void agregarNodo(Caravana &caravana,Tren tren){
    ptrTren aux = crearNodo(tren);
    if(verificarTipo(tren,"c1")==0){
        agregarPrimero(caravana,&aux);
    }
    else{
        agregarUltimo(caravana,&aux);
    }

}
void dibujarCaravana(Caravana &caravana);
void eliminarCaravana(Caravana &caravana);
void crearCaravana(Caravana &caravana);


void agregarPrimero(Caravana &caravana,ptrTren tren){
    caravana.primero= tren;
    caravana.ultimo= tren;
}

void agregarUltimo(Caravana &caravana,ptrTren tren){
    caravana.ultimo->siguiente=tren;
    tren->anterior=caravana.ultimo;
    caravana.ultimo=tren;
}
