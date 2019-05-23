#include <iostream>
#include <SDL.h>
#include "ManejoVentana.h"
#include "Estacion.h"
#include "VariablesFijas.h"
#include "Moneda.h"

using namespace std;

int main(int argc,char *args[])
{
    //variables para capear los fps
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    //variables para bloquear el maximo de FPS.
    int frameStart;
    int frameTime;

    Moneda moneda;
    Ventana ventana;
    Estacion estacion;

    crearVentana(ventana);//creo ventana
    InicializarVentana(ventana,"ClashUNLa",pos,pos,ancho,alto,SDL_WINDOW_RESIZABLE);//la inicializo
    crearEstacion(estacion,fila/3,columna/3,anchoCasillero,altoCasillero,ventana.p_render);//creo estacion
    crearMoneda(moneda,ventana.p_render);

    while(getRun(ventana)){


        //tomo el tiempo del primer frame
        frameStart = SDL_GetTicks();


        manejarEventos(ventana);
        renderClear(ventana);
        //aca iria los dibujar de cada objeto del juego
        dibujarEstacion(estacion,ventana.p_render);
        dibujarMoneda(moneda,ventana.p_render);
        renderPresent(ventana);
        actualizar(ventana);

        frameTime = SDL_GetTicks() - frameStart;

        //si lo que tarda es mas rapido de lo necesario para realizar la cantidad de FPS que asigne , realizara un delay
        if(frameDelay> frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    destruirEstacion(estacion);
    destruirVentana(ventana);
    return 0;
}
