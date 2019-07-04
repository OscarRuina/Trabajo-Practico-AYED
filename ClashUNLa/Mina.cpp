#include "Mina.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Moneda.h"
#include <iostream>
#include <fstream>

using namespace std;

void crearMina(Mina &mina,SDL_Renderer *renderer,int fil,int col,int tipo,int intervalo){
    mina.fil = fil;
    mina.col = col;
    mina.tipo= traerTipo(tipo);
    mina.cicloEntrega = 0;
    mina.intervalo=intervalo;
    mina.imagen = IMG_LoadTexture(renderer,"img/mina.png");

}

//verifica que tenga cajas disponibles, si las tiene , entrega la cantidad indicada en el ciclo
//sino entrega una caja vacia
int entregarCaja(Mina &mina){
    int ciclo = getCicloEntrega(mina);
    ciclo++;
    int cantidad;
    if((getCajasDisponibles(mina))>0){
        cantidad = mina.cajas[ciclo];
        setCajasDisponibles(mina,getCajasDisponibles(mina)-1);
        if(ciclo==4){
            setCicloEntrega(mina,0);
        }
        else{
            setCicloEntrega(mina,ciclo);
        }
    }
    else{
        cantidad = 0;
        setCicloEntrega(mina,0);
    }
    return cantidad;
}


void dibujarMina(Mina &mina,SDL_Renderer* renderer){

    mina.rectImg.x = mina.col*40;
    mina.rectImg.y = mina.fil*40;
    mina.rectImg.w = 40;
    mina.rectImg.h = 40;
    SDL_RenderCopy(renderer,mina.imagen,NULL,&(mina.rectImg));

}
void eliminarMina(Mina &mina){
}


//setea el permiso para generar cajas de las minas
void updateMina(Mina &mina){
    int ciclo = getCicloIntervalo(mina);
    ciclo++;
    if(ciclo==getIntervalo(mina)){
        setCajasDisponibles(mina,getCajasDisponibles(mina)+1);
        cout<<getCajasDisponibles(mina)<<endl;
        setCicloIntervalo(mina,0);
    }
    else{
            setCicloIntervalo(mina,ciclo);
    }
}

int getCicloEntrega(Mina &mina){
    return mina.cicloEntrega;

}
void setCicloEntrega(Mina &mina, int ciclo){
    mina.cicloEntrega=ciclo;
}

void resetearCajasMina(Mina &mina){
    mina.cajasDisponibles=0;
}

void setTipoMineral(Mina &mina,TiposMinerales tipo){
    mina.tipo=tipo;
}
TiposMinerales getTipoMineral(Mina &mina){
    return mina.tipo;
}

void mostrarTipoMina(Mina &mina){
    cout<<mina.tipo<<endl;

}

void setIntervalo(Mina &mina,int intervalo){
    mina.intervalo=intervalo;
}
int getIntervalo(Mina &mina){
    return mina.intervalo;
}

void setCicloIntervalo(Mina &mina,int intervalo){
     mina.cicloIntervalo=intervalo;

}
int getCicloIntervalo(Mina &mina){
    return mina.cicloIntervalo;
}


void setCajasDisponibles(Mina &mina,int cajasDisponibles){
    mina.cajasDisponibles=cajasDisponibles;
}
int getCajasDisponibles(Mina &mina){
    return mina.cajasDisponibles;
}
