#include "Tren.h"
#include <stdlib.h>
#include <string.h>

/*Implemtacion de primitivas*/
void crearTren(Tren &tren,char tipo[],char direccion[],int fil,int col,int kilos){
    strcpy(tren.tipo,tipo);
    tren.c =col;
    tren.f = fil;
    tren.tipoMineral = vacio;
    tren.monedas = 0;
    tren.kilos = kilos;
    tren.anterior.columnaAnterior=0;
    tren.anterior.filaAnterior=-1;
    setDireccion(tren,direccion);

    tren.ciclo = 0;

    tren.rectImag.x=col*40;
    tren.rectImag.y=fil*40;
    tren.rectImag.w=40;
    tren.rectImag.h=40;

}


void dibujarTren(Tren &tren,SDL_Renderer* renderer){
    int ciclo = getCiclo(tren);

    char imagen[30] = "img/";
    strcat(imagen,tren.tipo);strcat(imagen,"/");
    strcat(imagen,tren.direccion);strcat(imagen,"/");
    char cadenaIntervalo[5];
    itoa(ciclo,cadenaIntervalo,10);
    strcat(imagen,cadenaIntervalo);strcat(imagen,".png");

    //evaluamos los desplazamientos
    int velY=0;
    int velX=0;
    if(!verificarDireccion(tren,"aba"))velX=1;
    if(!verificarDireccion(tren,"arr"))velX=-1;
    if(!verificarDireccion(tren,"der"))velY=1;
    if(!verificarDireccion(tren,"izq"))velY=-1;

    moverTren(tren,velY,velX);


    tren.imagen=IMG_LoadTexture(renderer,imagen);

    SDL_RenderCopy(renderer,tren.imagen,NULL,&(tren.rectImag));
    ciclo++;
    setCiclo(tren,ciclo);
    if(ciclo==9){
        setCiclo(tren,1);
    }

}

bool verificarDireccion(Tren &tren,char direc[]){
    return strcmp(tren.direccion,direc);
}


void moverTren(Tren &tren, int velX,int velY){
    tren.rectImag.x=tren.rectImag.x+velX;
    tren.rectImag.y=tren.rectImag.y+velY;


    tren.rectImag.w=40;//70
    tren.rectImag.h=40  ;//70
}

void cambiarFilaColumna(Tren &tren){
    if(!verificarDireccion(tren,"aba")){
        tren.f = tren.f+1;
    }
    else if(!verificarDireccion(tren,"arr")){
        tren.f = tren.f-1;
    }

    else if(!verificarDireccion(tren,"der")){
        tren.c = tren.c+1;
    }

    else if(!verificarDireccion(tren,"izq")){
        tren.c = tren.c-1;
    }
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

void setCiclo(Tren &tren,int ciclo){
    tren.ciclo=ciclo;
}
int getCiclo(Tren &tren){
    return tren.ciclo;
}
void setColumna(Tren &tren,int col){
    tren.c = col;
}

int getColumna(Tren &tren){
    return tren.c;
}

void setFila(Tren &tren,int fil){
    tren.f = fil;
}

int getFila(Tren &tren){
    return tren.f;
}




bool verificarTipo(Tren &tren,char tipo[]){
    return strcmp(tren.direccion,tipo);
}

bool compararTren(Tren &tren,Tren &tren2){
    bool iguales = true;
    if(tren.tipo!=tren2.tipo){
        iguales= false;
    }
    if(strcmp(tren.direccion,tren2.direccion)!=0){
        iguales= false;
    }
    if(tren.rectImag.x!=tren2.rectImag.x){
        iguales= false;
    }
    return iguales;
}


void setPosicionAnterior(Tren &tren,posicionAnterior anterior){
    tren.anterior=anterior;

}
posicionAnterior getPosicionAnterior(Tren &tren){
    return tren.anterior;
}

int getMonedas(Tren &tren){
    return tren.monedas;
}
void setMonedas(Tren &tren,int monedas){
    tren.monedas=monedas;
}

int getKilos(Tren &tren){
    return tren.kilos;
}

void setKilos(Tren &tren,int kilos){
    tren.kilos=kilos;
}


void mostrarTrenFC(Tren &tren){
    cout<<tren.anterior.columnaAnterior<<"-"<<tren.anterior.filaAnterior<<endl;

}

bool compararFilaColumna(Tren &este,Tren &otro){
    return((getColumna(este)==getColumna(otro))&&(getFila(este)==getFila(otro)));
}
