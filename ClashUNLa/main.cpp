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
#include "Mina.h"

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

/*ResultadoComparacion compararListaBandidos(PtrDato ptrDato1, PtrDato ptrDato2){
    int dato1 = ((Bandido*)ptrDato1)->rectImagen.x;
    int dato2 = ((Bandido*)ptrDato2)->rectImagen.x;
    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }

}*/

ResultadoComparacion compararListaMonedas(PtrDato ptrDato1,PtrDato ptrDato2){
    int dato1 = ((Moneda*)ptrDato1)->rectImg.x+((Moneda*)ptrDato1)->rectImg.y;
    int dato2 = ((Moneda*)ptrDato2)->rectImg.x+((Moneda*)ptrDato2)->rectImg.y;
    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}
ResultadoComparacion compararListaMinas(PtrDato ptrDato1,PtrDato ptrDato2){
    TiposMinerales dato1 = ((Mina*)ptrDato1)->tipo;
    TiposMinerales dato2 = ((Mina*)ptrDato2)->tipo;
    if(CompararMinerales(dato1,dato2)==0){
        return IGUAL;
    }
    return MENOR;
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
    crearTren(*tren,"c1","aba",0,0,0);

    Lista listaTrenes;
    crearLista(listaTrenes,compararListaTrenes);
    adicionarPrincipio(listaTrenes,tren);

    //variable estacion
    Estacion* estacion = new Estacion;
    crearEstacion(*estacion,ventana.p_render);
    setEstacion(mapa.bloques[getFila(*estacion)][getColumna(*estacion)],estacion);
    //variable moneda
    Lista listaMonedas;
    crearLista(listaMonedas,compararListaMonedas);


    Bandido *bandido = new Bandido;
    //crearBandido(*bandido,ventana.p_render);
    //setBandido(mapa.bloques[getFila(*bandido)][getColumna(*bandido)],bandido);



    Lista listaMinas;
    crearLista(listaMinas,compararListaMinas);
    generarListaMinas(ventana,mapa,listaMinas);

    bool doOnce = true;
    bool turnoMoneda = true;
    int generarMonedas = 0;


    int ciclosRender = 0;


    while(getRun(ventana)){


                renderClear(ventana);
                dibujarMapa(mapa,ventana.p_render);


                while(doOnce){
                    renderPresent(ventana);
                    doOnce = false;

                }
                if(ciclosRender==0){
                    cout<<tren->monedas<<endl;
                    evaluarGrid(listaTrenes,ventana,mapa,*tren);
                    setListaEstadoAnterior(listaTrenes);
                    setFCListaTrenes(listaTrenes);
                    ManejarEventos(ventana,*tren);
                    setListaDireccionTrenes(listaTrenes);//cambia la direccion de los vagones dependiendo la direccion del que esta adelante
                }
                //tomo el tiempo del primer frame
                frameStart = SDL_GetTicks();

                evaluarLimites(ventana,mapa,*tren);
                dibujarMapa(mapa,ventana.p_render);
                dibujarEstacion(*estacion,ventana.p_render);



                renderBandidos(*bandido,ventana.p_render,mapa);
                renderListaTrenes(listaTrenes,ventana.p_render);
                renderListaMinas(listaMinas,ventana.p_render);
                renderListaMonedas(listaMonedas,ventana.p_render,turnoMoneda);



                renderPresent(ventana);
                frameTime = SDL_GetTicks() - frameStart;
                //si lo que tarda es mas rapido de lo necesario para realizar la cantidad de FPS que asigne , realizara un delay
                if(frameDelay> frameTime){
                    SDL_Delay(frameDelay - frameTime);
                }

                ciclosRender++;


                generarMonedas++;
                turnoMoneda=false;



                if(ciclosRender==40){

                    verificarEstadoListaMonedas(listaMonedas,mapa);
                    verificarColisionVagones(ventana,listaTrenes,*tren);
                    ciclosRender = 0;
                    setTurno(ventana,getTurno(ventana)+1);
                    turnoMoneda=true;
                }

                if(generarMonedas==120){
                    generarListaMonedas(ventana,listaMonedas,mapa);
                    generarMonedas=0;
                }





    }
    eliminarLista(listaTrenes);
    eliminarLista(listaMonedas);

    destruirEstacion(*estacion);
    destruirTren(*tren);
    destruirVentana(ventana);
    return 0;
}


