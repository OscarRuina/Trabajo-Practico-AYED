#include "FuncionesLista.h"
#include "Tren.h"
#include "Mina.h"
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

void mostrarKilosLista(Lista &lista){
PtrNodoLista cursor;
    if(longitud(lista)>0){
        cursor = siguiente(lista,primero(lista));
        while(cursor!=finLista()){
            Tren* tren = ((Tren*)cursor->ptrDato);
            mostrarKilos(*tren);
            cursor = siguiente(lista,cursor);
    }
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void generarListaMonedas(Ventana &ventana,Lista &lista,Mapa &mapa){
    ifstream fin("Moneda.txt");
    int cantMonedas;
    fin>>cantMonedas;
    //cout<<cantMonedas;
    if(longitud(lista)<cantMonedas){
        Moneda *moneda = new Moneda;

        crearMoneda(*moneda,ventana.p_render);
        if(!mapa.bloques[moneda->fil][moneda->col].ocupado){

            setMoneda(mapa.bloques[moneda->fil][moneda->col],moneda);
            adicionarFinal(lista,moneda);
        }
    }
}
//dibuja la lista de monedas
void renderListaMonedas(Lista &lista,SDL_Renderer *renderer,bool turnoMoneda){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Moneda* moneda = (Moneda*)cursor->ptrDato;
        dibujarMoneda(*moneda,renderer,turnoMoneda);
        cursor=siguiente(lista,cursor);
    }
}

void mostrarMonedas(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Moneda* moneda = (Moneda*)cursor->ptrDato;
        cursor=siguiente(lista,cursor);
    }
}


//si el tren choco con la moneda o su vida util llega a su fin, el estado sera puesto en falso ,
//luego verifico su estado y si es falso , elimina la moneda ylo saco d ela lista
void verificarEstadoListaMonedas(Lista &lista,Mapa &mapa){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Moneda* moneda = (Moneda*)cursor->ptrDato;
        if(moneda->activa==0){
            liberarBloque(mapa.bloques[moneda->fil][moneda->col]);
            eliminarNodo(lista,cursor);
        }
        cursor=siguiente(lista,cursor);
    }
    reordenar(lista);
}


//verifica que la vida del bandido no haya expirado,
//si expiro , lo remueve de la lista y libera los bloques.
void verificarEstadoListaBandidos(Lista &lista,Mapa &mapa){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Bandido *bandido;
        bandido = (Bandido*) cursor->ptrDato;
        if(bandido->activo==0){
            int minFil = (getFila(*bandido)-1);
            int minCol = (getColumna(*bandido)-1);
            int maxFil = (getFila(*bandido)+1);
            int maxCol = (getColumna(*bandido)+1);
            for(int i =minFil; i<=maxFil;i++){
                for(int j = minCol ;j<=maxCol;j++){
                liberarBloqueBandido(mapa.bloques[i][j]);
                }
            }

            destruirBandido(*bandido);
            eliminarNodo(lista,cursor);
        }
        cursor=siguiente(lista,cursor);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void generarListaMinas(Ventana &ventana,Mapa &mapa,Lista &lista){
    ifstream fin("Minas.txt");
    int fil;
    int col;
    int tipo;
    int intervalo;
    while(!fin.eof()){
        fin>>fil>>col>>tipo>>intervalo;
        Mina *mina = new Mina;
        crearMina(*mina,ventana.p_render,fil,col,tipo,intervalo);
        setMina(mapa.bloques[mina->fil][mina->col],mina);
        if(longitud(lista)==0){
            adicionarPrincipio(lista,mina);
        }
        else{
            adicionarFinal(lista,mina);
        }
    }
}
void mostrarMineralesLista(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Mina* mina= (Mina*) cursor->ptrDato;
        mostrarTipoMina(*mina);
        cursor=siguiente(lista,cursor);
    }

}

//dibuja la lista de las minas
void renderListaMinas(Lista &lista,SDL_Renderer *renderer){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Mina* mina= (Mina*) cursor->ptrDato;
        dibujarMina(*mina,renderer);
        cursor=siguiente(lista,cursor);
    }
}


//updatea la vida las cajasd e las minas
void updateListaMinas(Lista &lista){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Mina* mina= (Mina*) cursor->ptrDato;
        updateMina(*mina);
        cursor=siguiente(lista,cursor);
    }
}
////////////////////////////////////////////////////////////////////////////////////////
int verificarCantidadDeMinerales(Lista &lista,TiposMinerales mineral){
    int cantidad = 0;
    PtrNodoLista cursor;
    cursor = siguiente(lista,primero(lista));
    while(cursor!=finLista()){
        Tren *tren = new Tren;
        tren = (Tren*)cursor->ptrDato;
        if(CompararMinerales(mineral,getTipoMineral(*tren))){
            cantidad+=getKilosOcupados(*tren);
        }
        cursor=siguiente(lista,cursor);
    }
    return cantidad;
}


//verifica que la cantidad de minerales en todos los trenes sea la solicitada por la comadna.
bool verificarComanda(Lista &lista,Comanda &comanda){
    bool estado = true;
    int cantCarbon,cantBronce,cantPlata,cantOro,cantPlatino;


    cantCarbon=verificarCantidadDeMinerales(lista,carbon);
    cantBronce=verificarCantidadDeMinerales(lista,bronce);
    cantPlata=verificarCantidadDeMinerales(lista,plata);
    cantOro=verificarCantidadDeMinerales(lista,oro);
    cantPlatino=verificarCantidadDeMinerales(lista,platino);
    if(cantCarbon<getCantidadCarbon(comanda)){
        estado = false;
    }
    if(cantBronce<getCantidadBronce(comanda)){
        estado = false;
    }
    if(cantPlata<getCantidadPlata(comanda)){
        estado = false;
    }
    if(cantOro<getCantidadOro(comanda)){
        estado = false;
    }
    if(cantPlatino<getCantidadPlatino(comanda)){
       estado = false;
       }
    return estado ;
}
////////////////////////////////////////////////////////////////////////////////////////
//verifica que no exista mas de 2 bandidos , y si no existen agrega uno nuevo
void generarListaBandidos(Ventana &ventana, Mapa &mapa,Lista &lista){
    if(longitud(lista)<2){
        Bandido *bandido = new Bandido;
        crearBandido(*bandido,ventana.p_render);
        int minFil =0;int minCol =0;int maxFil = 0;int maxCol =0;
        minFil = getFila(*bandido)-1;
        maxFil = getFila(*bandido)+1;
        minCol = getColumna(*bandido)-1;
        maxCol = getColumna(*bandido)+1;
        for(int i = minFil;i<=maxFil;i++){
            for(int j = minCol;j<=maxCol;j++){
                if(((i>=0)&&(i<=14))&&((j>=0)&&(j<=19))){
                    setBandido(mapa.bloques[i][j],bandido);
                }
            }

        }


        if(listaVacia(lista)){
            adicionarPrincipio(lista,bandido);
            }
        else{
            adicionarFinal(lista,bandido);
            }
        }
    }


void renderListaBandido(Lista &lista,SDL_Renderer* renderer,bool turno){
    PtrNodoLista cursor;
    cursor = primero(lista);
    while(cursor!=finLista()){
        Bandido *bandido;
        bandido = (Bandido*) cursor->ptrDato;
        dibujarBandido(*bandido,renderer,turno);
        cursor= siguiente(lista,cursor);
    }

}

void pagarBandido(Ventana &ventana,Lista &lista,int cantidad)
{
    bool terminado = false;
    bool destruir = false;
    if(longitud(lista)<2)
    {
        cout<<"NO PUDISTE PAGAR"<<endl;
    }
    else{
    PtrNodoLista cursor;
    cursor = siguiente(lista,primero(lista));
    while(cursor!=finLista()&&(!terminado)){
        Tren *tren;
        tren = (Tren*) cursor->ptrDato;

            if(getKilosOcupados(*tren)<cantidad){
                destruir = true;
            }
            if(getKilosOcupados(*tren)>=cantidad)
            {
                setKilosOcupados(*tren,getKilosOcupados(*tren)-cantidad);
                terminado = true;
                destruir = false;
            }

          cursor = siguiente(lista,cursor);
         }
    if(destruir){
        eliminarNodoUltimo(lista);
    }
    }
}
