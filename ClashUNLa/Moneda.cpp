#include "Moneda.h"

void crearMoneda(Moneda &moneda,SDL_Renderer* renderer){
    moneda.width = 70;
    moneda.height = 70;
    moneda.posX = 20;
    moneda.posY = 20;
    moneda.vidaUtil = generarNumeroRandom();
    moneda.textura = IMG_LoadTexture(renderer,"img/moneda.png");

    moneda.destino.h = moneda.height;
    moneda.destino.w = moneda.width;
    moneda.destino.x = moneda.posX;
    moneda.destino.y = moneda.posY;
}

void dibujarMoneda(Moneda &moneda,SDL_Renderer* renderer){
    SDL_RenderCopy(renderer,moneda.textura,NULL,&moneda.destino);

}

void updateMoneda(Moneda &moneda){
    int turno = 0;
    while(turno<moneda.vidaUtil){

        turno++;
    }
    destruirMoneda(moneda);
}


int generarNumeroRandom(){
    int minimo = 7;
    int maximo = 20;
    return (rand() % ((maximo - minimo) + 1) + minimo);
    }

void destruirMoneda(Moneda &moneda){
    SDL_DestroyTexture(moneda.textura);

}
