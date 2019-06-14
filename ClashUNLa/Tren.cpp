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
void dibujarTren(Tren &tren,SDL_Renderer* renderer,int turno){
    char imagen[30] = "img/";
    strcat(imagen,tren.tipo);strcat(imagen,"/");
    strcat(imagen,tren.direccion);strcat(imagen,"/");
    char cadenaIntervalo[5];
    itoa(turno,cadenaIntervalo,10);
    strcat(imagen,cadenaIntervalo);strcat(imagen,".png");


    //evaluamos los desplazamientos
    int velY=0;
    int velX=0;
    if(!verificarDireccion(tren,"aba"))velX=3;
    if(!verificarDireccion(tren,"arr"))velX=-3;
    if(!verificarDireccion(tren,"der"))velY=3;
    if(!verificarDireccion(tren,"izq"))velY=-3;

    moverTren(tren,velY,velX);

    tren.imagen=IMG_LoadTexture(renderer,imagen);

    SDL_RenderCopy(renderer,tren.imagen,NULL,&(tren.rectImag));
}

bool verificarDireccion(Tren &tren,char direc[]){
    return strcmp(tren.direccion,direc);
}

void moverTren(Tren &tren, int velX,int velY){

    tren.rectImag.x=tren.rectImag.x+velX;
    tren.rectImag.y=tren.rectImag.y+velY;
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

