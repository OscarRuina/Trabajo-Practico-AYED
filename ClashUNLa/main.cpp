#include <iostream>
#include "ManejoVentana.h"
#include "VariablesFijas.h"

using namespace std;

int main(int argc,char *args[])
{
    Ventana ventana;
    crearVentana(ventana);
    InicializarVentana(ventana,"ClashUNLa",pos,pos,ancho,alto,SDL_WINDOW_RESIZABLE);
    while(ventana.run){
        manejarEventos(ventana);
        render(ventana);
        actualizar(ventana);
    }
    destruirVentana(ventana);
    return 0;
}
