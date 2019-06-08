#include "Tren.h"
#include <stdlib.h>
#include <string.h>
/*Implemtacion de primitivas*/
void crearTren(Tren &tren,char tipo[], int f,int c, char direccion[], int anchoCasillero, int altoCasillero, int altoSprite){
    strcpy(tren.tipo,tipo);
    tren.f=f;//coordenada logica y
    tren.c=c;//coordenada logica x
    strcpy(tren.direccion,direccion);
    tren.anchoCasillero=anchoCasillero;
    tren.altoCasillero=altoCasillero;
    tren.altoSprite=altoSprite;
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
void dibujarTren(Tren &tren,SDL_Renderer* renderer,int intervalo){
    char imagen[30] = "img/";
    strcat(imagen,tren.tipo);strcat(imagen,"/");

    strcat(imagen,tren.direccion);strcat(imagen,"/");

    char cadenaIntervalo[5];
    itoa(intervalo,cadenaIntervalo,10);
    strcat(imagen,cadenaIntervalo);strcat(imagen,".png");

    tren.imagen=IMG_LoadTexture(renderer,imagen);

    //evaluamos los desplazamientos
    int desplazamientoHorizontal=0;
    int desplazamientoVertical=0;
    if(strcmp(tren.direccion,"aba")==0)desplazamientoVertical=1;
    if(strcmp(tren.direccion,"arr")==0)desplazamientoVertical=-1;
    if(strcmp(tren.direccion,"der")==0)desplazamientoHorizontal=1;
    if(strcmp(tren.direccion,"izq")==0)desplazamientoHorizontal=-1;

    tren.rectImag.y=((tren.f*tren.altoCasillero)+tren.altoCasillero-(tren.altoSprite-tren.altoCasillero))+(desplazamientoVertical*(tren.altoCasillero/10)*intervalo);//coordenada de dibujo y
    tren.rectImag.x=((tren.c*tren.anchoCasillero)+tren.anchoCasillero)+(desplazamientoHorizontal*(tren.anchoCasillero/10)*intervalo);//coordenada de dibujo x
    tren.rectImag.w=tren.anchoCasillero;//70
    tren.rectImag.h=tren.altoSprite;//70

    SDL_RenderCopy(renderer,tren.imagen,NULL,&(tren.rectImag));
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

