#include <iostream>
#include "ManejoVentana.h"
#include "Estacion.h"
#include "VariablesFijas.h"

using namespace std;

int main(int argc,char *args[])
{
    Ventana ventana;
    Estacion estacion;
    crearVentana(ventana);//creo ventana
    InicializarVentana(ventana,"ClashUNLa",pos,pos,ancho,alto,SDL_WINDOW_RESIZABLE);//la inicializo
    crearEstacion(estacion,fila/3,columna/3,anchoCasillero,altoCasillero,ventana.p_render);//creo estacion
    while(getRun(ventana)){
        manejarEventos(ventana);
        renderClear(ventana);
        //aca iria los dibujar de cada objeto del juego
        dibujarEstacion(estacion,ventana.p_render);
        renderPresent(ventana);
        actualizar(ventana);
    }
    destruirEstacion(estacion);
    destruirVentana(ventana);
    return 0;
}
