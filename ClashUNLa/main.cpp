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
#include "Lista.h"
#include "FuncionesLista.h"

ResultadoComparacion compararListaTrenes(PtrDato ptrDato1,PtrDato ptrDato2){
    int dato1 = ((Tren*) ptrDato1)->rectImag.x;
    int dato2 = ((Tren*) ptrDato2)->rectImag.x ;

    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}


using namespace std;

int main(int argc,char *args[])
{
    //variables para el manejo de fps
    const int FPS = 120;
    const int frameDelay = 1000/FPS;
    int frameStart;
    int frameTime;
    //variables ventana
    Ventana ventana;
    crearVentana(ventana);//creo ventana
    InicializarVentana(ventana,"ClashUNLa",pos,pos,ancho,alto,SDL_WINDOW_RESIZABLE);
    //variables para crear mapa
    Mapa mapa;
    crearMapa(mapa,ventana.p_render);

    //variables tren y lista de trenes
    Tren* tren = new Tren;
    crearTren(*tren,"c1");
    Lista listaTrenes;
    crearLista(listaTrenes,compararListaTrenes);
    adicionarPrincipio(listaTrenes,tren);
    //variable estacion
    Estacion* estacion = new Estacion;
    crearEstacion(*estacion,ventana.p_render);
    //variable moneda
    Moneda moneda;
    crearMoneda(moneda,ventana.p_render);
    setEstacion(mapa.bloques[getFila(*estacion)][getColumna(*estacion)],estacion);


    bool doOnce = true;
    bool turnoMoneda = true;
    int ciclosRender = 0;
    int turno = getTurno(ventana);
    while(getRun(ventana)){

                renderClear(ventana);
                dibujarMapa(mapa,ventana.p_render);
                while(doOnce){
                    renderPresent(ventana);
                    doOnce = false;
                }
                if(ciclosRender==0){
                    ManejarEventos(ventana,*tren);
                    evaluarColiciones(listaTrenes,ventana,mapa,*tren);
                }
                //tomo el tiempo del primer frame
                frameStart = SDL_GetTicks();
                dibujarMapa(mapa,ventana.p_render);
                dibujarEstacion(*estacion,ventana.p_render);
                dibujarMoneda(moneda,ventana.p_render,turnoMoneda);
                renderListaTrenes(listaTrenes,ventana.p_render);




                renderPresent(ventana);
                frameTime = SDL_GetTicks() - frameStart;
                //si lo que tarda es mas rapido de lo necesario para realizar la cantidad de FPS que asigne , realizara un delay
                if(frameDelay> frameTime){
                    SDL_Delay(frameDelay - frameTime);
                }
                ciclosRender++;
                turnoMoneda= false;
                if(ciclosRender==40){

                    ciclosRender = 0;
                    setTurno(ventana,getTurno(ventana)+1);
                    setListaDireccionAnterior(listaTrenes);
                    setListaDireccionTrenes(listaTrenes);
                    turnoMoneda= true;
                }

    }
    destruirEstacion(*estacion);
    destruirTren(*tren);
    destruirVentana(ventana);
    return 0;
}


