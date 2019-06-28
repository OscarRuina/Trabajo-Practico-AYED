#include "Mapa.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Bloque.h"

using namespace std;

void crearMapa(Mapa &mapa,SDL_Renderer *renderer){
    mapa.ancho = 800;
    mapa.alto = 600;
    mapa.col = mapa.ancho/40;
    mapa.fil = mapa.alto/40;
    mapa.textura = IMG_LoadTexture(renderer,"img/suelo.png");
    mapa.destino.x = 0;
    mapa.destino.y = 0;
    mapa.destino.w = mapa.ancho;
    mapa.destino.h = mapa.alto;
    //mapa.bloques = crearBloques(mapa.fil,mapa.col);

    int id = 1;
    for(int i = 0 ; i<mapa.fil;i++){
        for(int j = 0;j< mapa.col;j++){
            mapa.bloques[i][j]=crearBloque(id,i+1,j+1);
            id++;
        }
    }
}
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer){
    SDL_RenderCopy(renderer,mapa.textura,NULL,&mapa.destino);

}
void destruirMapa(Mapa &mapa){

    SDL_DestroyTexture(mapa.textura);
}

void mostrarBloquesMapa(Mapa &mapa){
    for(int i = 0;i<mapa.fil;i++){
        for(int j=0 ;j<mapa.col;j++ ){
            mostrarBloque(mapa.bloques[i][j]);
        }
    }
}


void evaluarColiciones(Lista &lista,Ventana &ventana,Mapa &mapa,Tren &tren){
    evaluarLimites(ventana,mapa,tren);
    evaluarGrid(lista,ventana,mapa,tren);
}

void evaluarLimites(Ventana &ventana,Mapa &mapa,Tren &tren){
    if((tren.rectImag.x<0)||((tren.rectImag.x+40)>800)||(tren.rectImag.y<0)||((tren.rectImag.y+40)>600)){
        setRun(ventana,false);
        cout<<tren.rectImag.x<<endl;
        cout<<tren.rectImag.y<<endl;
    }
}

void evaluarGrid(Lista &lista,Ventana &ventana,Mapa &mapa,Tren &tren){
    Bloque bloque = mapa.bloques[tren.f][tren.c];
    if(bloque.ocupado){
            if(verificarTipo(tren,"c1")){
                cout<<"---"<<endl;
                if(bloque.estacion!=NULL&&tren.monedas>0){
                    colisionEstacion(lista,tren);
                }
            }

    }
}

void colisionEstacion(Lista &lista,Tren &tren){
    cout<<"Colision estacion"<<endl;
    int kilos = tren.monedas;
    tren.monedas=0;
    Tren* trenAux = new Tren;
    PtrNodoLista aux = ultimo(lista);
    Tren* trenAnterior = ((Tren*)aux->ptrDato);
    crearTren(*trenAux,"c2",trenAnterior->anterior.direccionAnterior,trenAnterior->anterior.filaAnterior,trenAnterior->anterior.columnaAnterior,kilos);
    adicionarFinal(lista,trenAux);

}
