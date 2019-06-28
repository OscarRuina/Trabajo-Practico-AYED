#include "Bandido.h"
#include "Bloque.h"
/*implementacion de primitivas*/
void crearBandido(Bandido &bandido,SDL_Renderer *renderer){
    cargarVariablesBandido(bandido);
    bandido.imagen = IMG_LoadTexture(renderer,"img/villano.png");
}

void cargarVariablesBandido(Bandido &bandido){}

void dibujarBandido(Bandido &bandido,SDL_Renderer *renderer){
    bandido.rectImagen.x = bandido.c*40;
    bandido.rectImagen.y = bandido.f*40;
    bandido.rectImagen.h = 40;
    bandido.rectImagen.w = 40;
    SDL_RenderCopy(renderer,bandido.imagen,NULL,&(bandido.rectImagen));
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
