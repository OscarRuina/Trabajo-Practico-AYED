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
   // cargarVariablesBandido(bandido);

        bandido.c = 10;
        bandido.f= 10;
        bandido.intervaloBandido = 5;
        bandido.vidaBandido = 300;
        bandido.activo = true;
        bandido.imagen = IMG_LoadTexture(renderer,"img/villano.png");
}
void crearBandido(Bandido &bandido,SDL_Renderer *renderer,int posX, int posY, int vida){

        bandido.c = posY;
        bandido.f= posX;
        bandido.intervaloBandido = 5;
        bandido.vidaBandido = vida;
        bandido.activo = true;
        bandido.imagen = IMG_LoadTexture(renderer,"img/villano.png");


}
void cargarVariablesBandido(Bandido &bandido){}

void dibujarBandido(Bandido &bandido,SDL_Renderer *renderer,bool turnoBandido){
    bandido.rectImagen.x = bandido.c*40;
    bandido.rectImagen.y = bandido.f*40;
    bandido.rectImagen.h = 40;
    bandido.rectImagen.w = 40;
    SDL_RenderCopy(renderer,bandido.imagen,NULL,&(bandido.rectImagen));


    /*if(turnoBandido){
        bandido.vidaBandido--;
    }
    if(bandido.vidaBandido<0){
        bandido.activo = false;
        destruirBandido(bandido);
    }*/

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

int generarNumeroRandomB(int minimo,int maximo){
    srand((unsigned int)time(NULL));
    int rango = (maximo-minimo)+1;

    return (minimo+rand()%rango);
}
