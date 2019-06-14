#include <iostream>
#include <string.h>//permite utilizar strcat(char,char) strcpy(char,char);
#include <conio.h>// agrega la funcuion getch(); que es trabante de procesos
#include <stdlib.h>
#include <SDL.h>
#include "ManejoVentana.h"
#include "Estacion.h"
#include "Moneda.h"
#include "Mapa.h"
#include "Tren.h"
#include "VariablesFijas.h"
using namespace std;

int main(int argc,char *args[])
{
    //variables para capear los fps
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    //variables para bloquear el maximo de FPS.
    int frameStart;
    int frameTime;
    Ventana ventana;
    Moneda moneda;
    Tren tren;
    Estacion estacion;
    Mapa mapa;


    crearVentana(ventana);//creo ventana
    InicializarVentana(ventana,"ClashUNLa",pos,pos,ancho,alto,SDL_WINDOW_RESIZABLE);//la inicializo
    crearEstacion(estacion,fila/3,columna/3,anchoCasillero,altoCasillero,ventana.p_render);//creo estacion
    crearMoneda(moneda,ventana.p_render);
    crearMapa(mapa,ventana.p_render);
    crearTren(tren,"c1", 0, 0,anchoCasillero, altoCasillero, altoSprite);


    while(getRun(ventana)){

            ManejarEventos(ventana,tren);
            //tomo el tiempo del primer frame
            frameStart = SDL_GetTicks();
            renderClear(ventana);
            //aca iria los dibujar de cada objeto del juego
            dibujarMapa(mapa,ventana.p_render);
            dibujarEstacion(estacion,ventana.p_render);
            dibujarMoneda(moneda,ventana.p_render);
            dibujarTren(tren,ventana.p_render);
            renderPresent(ventana);

            frameTime = SDL_GetTicks() - frameStart;
            //si lo que tarda es mas rapido de lo necesario para realizar la cantidad de FPS que asigne , realizara un delay
            if(frameDelay> frameTime){
                SDL_Delay(frameDelay - frameTime);
            }




    }
    destruirEstacion(estacion);
    destruirTren(tren);
    destruirVentana(ventana);
    return 0;
}

