#include "Moneda.h"
#include <iostream>
#include <time.h>
#include "FuncionesLista.h"
using namespace std;

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer){

    moneda.fil = generarNumeroRandom(0,14);
    moneda.col = generarNumeroRandom(0,19);
    moneda.vidaUtil = generarNumeroRandom(15,25);
    moneda.activa = true;
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
        moneda.activa = false;
        destruirMoneda(moneda);
    }
}

void updateMoneda(Moneda &moneda){
}


int generarNumeroRandom(int minimo,int maximo){
    srand((unsigned int)time(NULL));
    int rango = (maximo-minimo)+1;

    return (minimo+rand()%rango);
}

void destruirMoneda(Moneda &moneda){
    SDL_DestroyTexture(moneda.textura);
}
