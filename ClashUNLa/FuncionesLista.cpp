#include "FuncionesLista.h"
#include "Tren.h"
#include <SDL.h>
#include "Lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ManejoVentana.h"
#include <iostream>
#include <fstream>

using namespace std;

void renderListaTrenes(Lista &lista,SDL_Renderer *renderer){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = (Tren*) cursor->ptrDato;
        dibujarTren(*tren,renderer);
        cursor=siguiente(lista,cursor);
    }
}

void setFCListaTrenes(Lista &lista){
    PtrNodoLista cursor;
    PtrNodoLista aux;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = (Tren*)cursor->ptrDato;
        if(cursor!=primero(lista)){
            aux = anterior(lista,cursor);
            Tren* trenAux = (Tren*) aux->ptrDato;
            tren->c= trenAux->anterior.columnaAnterior;
            tren->f= trenAux->anterior.filaAnterior;

        }
        cursor=siguiente(lista,cursor);
    }
}

void setListaEstadoAnterior(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren* tren = (Tren*)cursor->ptrDato;
        posicionAnterior posAnterior;
        posAnterior.columnaAnterior=tren->c;
        posAnterior.filaAnterior=tren->f;
        strcpy(posAnterior.direccionAnterior,getDireccion(*tren));
        tren->anterior=posAnterior;
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
            strcpy(direc,trenAnterior->anterior.direccionAnterior);
            setDireccion(*tren,direc);
        }
        cursor = siguiente(lista,cursor);
    }
}

void generarListaMonedas(Ventana &ventana,Lista &lista,Mapa &mapa){
    ifstream fin("Moneda.txt");

    int cantMonedas;
    fin>>cantMonedas;
    //cout<<cantMonedas;
    while(longitud(lista)<cantMonedas){
        Moneda *moneda = new Moneda;
        crearMoneda(*moneda,ventana.p_render);
        adicionarFinal(lista,moneda);
    }
}

void renderListaMonedas(Lista &lista,SDL_Renderer *renderer,bool turnoMoneda){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Moneda* moneda = (Moneda*)cursor->ptrDato;
        dibujarMoneda(*moneda,renderer,turnoMoneda);
        cursor=siguiente(lista,cursor);
    }
}


void mostrarDirecciones(Lista &lista){
 PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Tren * tren = (Tren*)cursor->ptrDato;
        mostrarTrenFC(*tren);
        cursor = siguiente(lista,cursor);
        }
}

void verificarColisionVagones(Ventana &ventana,Lista &lista,Tren &tren){
    PtrNodoLista cursor;
    cursor = siguiente(lista,primero(lista));
    while(cursor!=finLista()){
        Tren* trenAux = (Tren*)cursor->ptrDato;
        if(compararFilaColumna(tren,*trenAux)){
            cout<<"Choco con otro vagon"<<endl;
            setRun(ventana,false);
        }
        cursor=siguiente(lista,cursor);

    }
}
