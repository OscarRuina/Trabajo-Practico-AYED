#include "ManejoVentana.h"
#include <iostream>
#include <SDL.h>

/*implementacion de primitivas*/
using namespace std;
void crearVentana(Ventana &ventana){
    ventana.p_ventana = 0;
    ventana.p_render = 0;
    ventana.run = true;
}

void setRun(Ventana &ventana,bool run){
    ventana.run = run;
}

bool getRun(Ventana &ventana){
    return ventana.run;
}

bool InicializarVentana(Ventana &ventana, const char *titulo,int posx,int posy,int ancho,int alto,int flags){
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0){//inicializa todo
        cout<<"SDL Inicializo correctamente"<<endl;
        ventana.p_ventana = SDL_CreateWindow(titulo,posx,posy,ancho,alto,flags);//creo ventana
        if(ventana.p_ventana != 0){
            cout<<"Ventana creada correctamente"<<endl;
            ventana.p_render = SDL_CreateRenderer(ventana.p_ventana,-1,0);//creo render
            if(ventana.p_render !=0){
                cout<<"Render creado correctamente"<<endl;
                SDL_SetRenderDrawColor(ventana.p_render,255,255,255,255);
            }
            else{
                cout<<"Fallo el Render"<<endl;
                setRun(ventana,false);
            }
        }
        else{
            cout<<"Fallo la ventana"<<endl;
            setRun(ventana,false);
        }
    }
    else{
        cout<<"Fallo la inicializacion"<<endl;
        setRun(ventana,false);
    }
    cout<<"Inicio exitoso"<<endl;
    return ventana.run;
}

void manejarEventos(Ventana &ventana,Tren &tren){
    SDL_Event eventos;
    const unsigned char *keys;
    keys = SDL_GetKeyboardState(NULL);
    if(SDL_PollEvent(&eventos)){
        switch(eventos.type){
            case SDL_QUIT: setRun(ventana,false);//para salir de la aplicacion
            break;
            case SDL_KEYDOWN:
                if(keys[SDL_SCANCODE_LEFT]){
                    setDireccion(tren,"izq");
                    setColumna(tren,-1);
                }
                if(keys[SDL_SCANCODE_RIGHT]){
                    setDireccion(tren,"der");
                    setColumna(tren,+1);
                }
                if(keys[SDL_SCANCODE_UP]){
                    setDireccion(tren,"arr");
                    setFila(tren,-1);
                }
                if(keys[SDL_SCANCODE_DOWN]){
                    setDireccion(tren,"aba");
                    setFila(tren,+1);
                }
                break;
        }
    }
}

void renderClear(Ventana &ventana){
    SDL_RenderClear(ventana.p_render);
}

void renderPresent(Ventana &ventana){
    SDL_RenderPresent(ventana.p_render);
}

void actualizar(Ventana &ventana){

}

void destruirVentana(Ventana &ventana){
    cout<<"Cierro ventana"<<endl;
    SDL_DestroyRenderer(ventana.p_render);//destruyo render
    SDL_DestroyWindow(ventana.p_ventana);//destruyo ventana
    SDL_Quit();
}
