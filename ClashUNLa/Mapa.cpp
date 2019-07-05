#include "Mapa.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Bloque.h"
#include "Colisiones.h"
#include "FuncionesLista.h"

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

void evaluarGrid(Lista &lista,Ventana &ventana,Mapa &mapa,Tren &tren){
    Bloque bloque = mapa.bloques[tren.f][tren.c];
    if(bloque.ocupado){
            if(verificarTipo(tren,"c1")){
                if(bloque.estacion!=NULL&&tren.monedas>0){
                    colisionEstacion(lista,tren);
                }
                if(bloque.moneda!=NULL){
                    cout<<"COLISSION MONEDA"<<endl;
                    colisionMoneda(lista,tren,bloque);
                }
                if(bloque.mina!=NULL){
                    cout<<"COLISSION MINA"<<endl;
                    colisionMina(lista,tren,bloque);
                }
                if(bloque.bandido!=NULL){
                    cout<<"COLISSION BANDIDO"<<endl;
                    bool pagar = pagarBandidoTecla(ventana);
                    if(pagar==1){
                        cout<<"YA TE PAGUE BANDIDO"<<endl;
                            pagarBandido(ventana,lista,getCantidadRobo(*getBandido(bloque)));
                            setActivo(*getBandido(bloque),false);
                        }
                    else  {
                        setActivo(*getBandido(bloque),false);
                        colisionBandido(lista,tren,bloque,ventana);
                    }
                }
            }
        }
}

