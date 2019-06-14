#include "Tren.h"
#include <stdlib.h>
#include <string.h>
/*Implemtacion de primitivas*/
void crearTren(Tren &tren,char tipo[], int f,int c, int anchoCasillero, int altoCasillero, int altoSprite){
    strcpy(tren.tipo,tipo);
    tren.f=f;//coordenada logica y
    tren.c=c;//coordenada logica x
    setDireccion(tren,"aba");
    tren.anchoCasillero=anchoCasillero;
    tren.altoCasillero=altoCasillero;
    tren.altoSprite=altoSprite;
    tren.posTX=0;
    tren.posTY=0;
    tren.posImagen = 0;
    tren.rectImag.x=0;
    tren.rectImag.y=0;
    tren.rectImag.w=anchoCasillero;
    tren.rectImag.h=altoCasillero;

}
int getFila(Tren &tren){
    return tren.f;
}

int getColumna(Tren &tren){
    return tren.c;
}
void setFila(Tren &tren,int desplazamiento){
    tren.f = tren.f + desplazamiento;
}
void setColumna(Tren &tren,int desplazamiento){
    tren.c = tren.c + desplazamiento;
}
void dibujarTren(Tren &tren,SDL_Renderer* renderer){

    tren.imagen=IMG_LoadTexture(renderer,"img/c1/aba/0.png");

    //evaluamos los desplazamientos
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(tren.direccion,"aba")==0)desplazamientoVertical=2;
    if(strcmp(tren.direccion,"arr")==0)desplazamientoVertical=-2;
    if(strcmp(tren.direccion,"der")==0)desplazamientoHorizontal=2;
    if(strcmp(tren.direccion,"izq")==0)desplazamientoHorizontal=-2;

    moverTren(tren,desplazamientoHorizontal,desplazamientoVertical);

    SDL_RenderCopy(renderer,tren.imagen,NULL,&(tren.rectImag));
    tren.posImagen++;
    if(tren.posImagen==9){
        tren.posImagen=0;
    }
}




void cargarIzquierda(Tren &tren);
void cargarDerecha(Tren &tren);
void cargarArriba(Tren &tren);
void cargarAbajo(Tren &tren);

void moverTren(Tren &tren, int desplazamientoHorizontal,int desplazamientoVertical){

    tren.rectImag.x=tren.rectImag.x+desplazamientoHorizontal;
    tren.rectImag.y=tren.rectImag.y+desplazamientoVertical;
    tren.rectImag.w=tren.anchoCasillero;//70
    tren.rectImag.h=tren.altoSprite;//70
}
void destruirTren(Tren &tren){
    SDL_DestroyTexture(tren.imagen);
}
char* getDireccion(Tren &tren){
    return tren.direccion;
}
void setDireccion(Tren &tren,char direccion[]){
    strcpy(tren.direccion,direccion);
}

