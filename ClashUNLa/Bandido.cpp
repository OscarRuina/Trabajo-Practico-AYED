#include "Bandido.h"
#include "Bloque.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"
#include <string.h>

using namespace std;
/*implementacion de primitivas*/

void crearBandido(Bandido &bandido,SDL_Renderer *renderer){

    bandido.c = generarNumeroRandom(0,19);
    bandido.f= generarNumeroRandom(0,14);
    bandido.vidaBandido = generarNumeroRandom(25,35);
    bandido.tipo = generarNumeroRandom(1,5);
    bandido.activo = true;
    bandido.imagen = IMG_LoadTexture(renderer,"img/villano.png");


}


void dibujarBandido(Bandido &bandido,SDL_Renderer *renderer,bool turno){

    if(bandido.vidaBandido>0){
        bandido.rectImg.x = bandido.c*40;
        bandido.rectImg.y = bandido.f*40;
        bandido.rectImg.h = 40;
        bandido.rectImg.w = 40;
        SDL_RenderCopy(renderer,bandido.imagen,NULL,&(bandido.rectImg));
    }
    if(turno == 1){
        bandido.vidaBandido--;
    }
    if(bandido.vidaBandido<=0){
        bandido.activo=0;
    }
}



void destruirBandido(Bandido &bandido){
    SDL_DestroyTexture(bandido.imagen);
}

void setColumna(Bandido &bandido,int c){
    bandido.c = c;
}

void setFila(Bandido &bandido,int f){
    bandido.f = f;
}

int getColumna(Bandido &bandido){
    return bandido.c;
}

int getFila(Bandido &bandido){
    return bandido.f;
}

void setIntervaloBandido(Bandido &bandido, int ib){
    bandido.intervaloBandido =  ib;
}
void setVidaBandido(Bandido &bandido, int vb){
    bandido.vidaBandido = vb;
}
int getIntervaloBandido(Bandido &bandido){
    return bandido.intervaloBandido;
}
int getVidaBandido(Bandido &bandido){
    return bandido.vidaBandido;
}

