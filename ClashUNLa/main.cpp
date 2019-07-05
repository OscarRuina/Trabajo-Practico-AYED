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
#include "Comanda.h"
#include "Bandido.h"
#include "Colisiones.h"

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

ResultadoComparacion compararListaMinas(PtrDato ptrDato1,PtrDato ptrDato2){
    TiposMinerales dato1 = ((Mina*)ptrDato1)->tipo;
    TiposMinerales dato2 = ((Mina*)ptrDato2)->tipo;
    if(CompararMinerales(dato1,dato2)==0){
        return IGUAL;
    }
    return MENOR;
}

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

ResultadoComparacion compararListaBandidos(PtrDato ptrDato1,PtrDato ptrDato2){
    int dato1 = ((Bandido*)ptrDato1)->rectImg.x+((Bandido*)ptrDato1)->rectImg.y;
    int dato2 = ((Bandido*)ptrDato2)->rectImg.x+((Bandido*)ptrDato2)->rectImg.y;
    if (dato1 < dato2) {
        return MENOR;
    }else if (dato1 > dato2) {
        return MAYOR;
    }else{
        return IGUAL;
    }
}

void eliminarElementos(Lista &listaMinas,Lista &listaMonedas,Lista &listaBandidos,Lista &listaTrenes,Estacion *estacion,Tren *tren,Ventana &ventana){
    eliminarLista(listaMinas);
    eliminarLista(listaMonedas);
    eliminarLista(listaBandidos);
    eliminarLista(listaTrenes);
    destruirEstacion(*estacion);
    destruirTren(*tren);
    destruirVentana(ventana);
}

void renderElementos(Mapa &mapa,Estacion *estacion,Lista &listaMinas,Lista &listaMonedas,Lista &listaBandidos,Lista &listaTrenes,SDL_Renderer* renderer,bool turnoMoneda,bool  turnoBandido){

    dibujarMapa(mapa,renderer);
    dibujarEstacion(*estacion,renderer);
    renderListaMinas(listaMinas,renderer);
    renderListaMonedas(listaMonedas,renderer,turnoMoneda);
    renderListaBandido(listaBandidos,renderer,turnoBandido);
    renderListaTrenes(listaTrenes,renderer);

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
    //variable minas
    Lista listaMinas;
    crearLista(listaMinas,compararListaMinas);
    generarListaMinas(ventana,mapa,listaMinas);
    //variable moneda
    Lista listaMonedas;
    crearLista(listaMonedas,compararListaMonedas);
    //variable bandido
    Lista listaBandidos;
    crearLista(listaBandidos,compararListaBandidos);
    //variable comanda
    Comanda *comanda;
    crearComanda(*comanda);
    /////////////////////////////////////////////////////
    bool doOnce = true;
    bool Turno = true;
    bool TurnoBandido = true;
    int generarMonedas = 0;
    int ciclosRender = 0;
    int cicloBandido = 0;
    int intervaloMoneda = 0;
    int intervaloBandido = 0;
    int primerRender = 0;
    intervaloMoneda = setIntervaloMoneda();
    intervaloBandido = setIntervaloMoneda()*2.5;
    while(getRun(ventana)){
    int cicloBandido = getCiclo(ventana);

                //tomo el tiempo del primer frame
                frameStart = SDL_GetTicks();

                renderClear(ventana);
                dibujarMapa(mapa,ventana.p_render);

                while(doOnce){
                    renderPresent(ventana);
                    doOnce = false;
                    //mostrarMineralesLista(listaMinas);
                }
                if(ciclosRender==primerRender){
                    mostrarKilosLista(listaTrenes);
                    evaluarGrid(listaTrenes,ventana,mapa,*tren);
                    setListaEstadoAnterior(listaTrenes);
                    setFCListaTrenes(listaTrenes);
                    ManejarEventos(ventana,*tren);
                    setListaDireccionTrenes(listaTrenes);//cambia la direccion de los vagones dependiendo la direccion del que esta adelante
                }
                //tomo el tiempo del primer frame


                evaluarLimites(ventana,mapa,*tren);
                renderElementos(mapa,estacion,listaMinas,listaMonedas,listaBandidos,listaTrenes,ventana.p_render,Turno,TurnoBandido);


                renderPresent(ventana);
                frameTime = SDL_GetTicks() - frameStart;


                ciclosRender++;
                generarMonedas++;
                Turno=false;
                TurnoBandido=false;
                cicloBandido++;
                setCiclo(ventana,cicloBandido);
                if(cicloBandido==40*intervaloBandido){
                    generarListaBandidos(ventana,mapa,listaBandidos);
                    setCiclo(ventana,0);
                }
                if(ciclosRender==anchoCasillero){
                    verificarEstadoListaBandidos(listaBandidos,mapa);
                    verificarEstadoListaMonedas(listaMonedas,mapa);
                    verificarColisionVagones(ventana,listaTrenes,*tren);
                    setTurno(ventana,getTurno(ventana)+1);
                    updateListaMinas(listaMinas);
                    ciclosRender = 0;
                    Turno=true;
                    TurnoBandido=true;
                    if(verificarComanda(listaTrenes,*comanda)){
                            cout<<"GANO!!"<<endl;
                            setRun(ventana,false);
                       }
                }


                if(generarMonedas==40*intervaloMoneda){
                    generarListaMonedas(ventana,listaMonedas,mapa);
                    generarMonedas=0;

                }

                    //si lo que tarda es mas rapido de lo necesario para realizar la cantidad de FPS que asigne , realizara un delay
        if(frameDelay> frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    eliminarElementos(listaTrenes,listaBandidos,listaMinas,listaMonedas,estacion,tren,ventana);
    return 0;
}

