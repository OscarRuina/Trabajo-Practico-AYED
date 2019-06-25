#include "FuncionesLista.h"
#include "Tren.h"
#include <SDL.h>
#include "Lista.h"
#include <stdlib.h>
#include <string.h>

void renderListaTrenes(Lista &lista,SDL_Renderer *renderer){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = (Tren*) cursor->ptrDato;
        dibujarTren(*tren,renderer);
        cursor=siguiente(lista,cursor);
    }
}


void setListaDireccionAnterior(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = (Tren*)cursor->ptrDato;
        setDireccionAnterior(*tren,tren->direccion);
        cursor = siguiente(lista,cursor);
    }
}


void setListaDireccionTrenes(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = ((Tren*)cursor->ptrDato);
        if(cursor!=primero(lista)){
            PtrNodoLista ptrAnterior = anterior(lista,cursor);
            Tren* trenAnterior = (Tren*)ptrAnterior->ptrDato;
            char direc[4];
            strcpy(direc,trenAnterior->direccionAnterior);
            setDireccion(*tren,direc);
        }
        cursor = siguiente(lista,cursor);
    }

}
