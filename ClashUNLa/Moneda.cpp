#include "Moneda.h"
#include <iostream>
#include <time.h>
using namespace std;

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer){

    moneda.fil = generarNumeroRandom(0,14);
    moneda.col = generarNumeroRandom(0,19);
    moneda.vidaUtil = generarNumeroRandom(10,20);
    moneda.textura = IMG_LoadTexture(renderer,"img/moneda.png");

}

void dibujarMoneda(Moneda &moneda,SDL_Renderer* renderer,bool turno){
    if(moneda.vidaUtil>0){
        moneda.rectImg.x = 40*moneda.col;
    moneda.rectImg.y = 40*moneda.fil;
    moneda.rectImg.w = 40;
    moneda.rectImg.h = 40;
    SDL_RenderCopy(renderer,moneda.textura,NULL,&moneda.rectImg);
    }
    if(turno){
        moneda.vidaUtil--;
    }
    if(moneda.vidaUtil<0){
        destruirMoneda(moneda);
    }

}

void updateMoneda(Moneda &moneda){
    int turno = 0;
    while(turno<moneda.vidaUtil){

        turno++;
    }
    destruirMoneda(moneda);
}


int generarNumeroRandom(int minimo,int maximo){
    srand(time(NULL));
    return (rand() % ((maximo - minimo) + 1) + minimo);
}

void destruirMoneda(Moneda &moneda){
    SDL_DestroyTexture(moneda.textura);

}
