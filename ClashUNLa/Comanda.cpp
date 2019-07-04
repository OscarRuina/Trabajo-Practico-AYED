#include "Comanda.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void crearComanda(Comanda &comanda){
    ifstream fin("Comanda.txt");
    fin>>comanda.cantidadCarbon>>comanda.cantidadBronce>>comanda.cantidadPlata>>comanda.cantidadOro>>comanda.cantidadPlatino;
}

void eliminarComanda(Comanda &comanda){
}
void dibujarGanadoComanda(Comanda &comanda){
}
void dibujarGameOverComanda(Comanda &comanda){
}

void mostrarComanda(Comanda &comanda){
    cout<<comanda.cantidadCarbon<<"-"<<comanda.cantidadBronce<<"-"<<comanda.cantidadPlata<<"-"<<comanda.cantidadOro<<"-"<<comanda.cantidadPlatino<<endl;
}
int getCantidadCarbon(Comanda &comanda){
    return comanda.cantidadCarbon;
}
int getCantidadBronce(Comanda &comanda){
    return comanda.cantidadBronce;
}
int getCantidadPlata(Comanda &comanda){
    return comanda.cantidadPlata;
}
int getCantidadOro(Comanda &comanda){
    return comanda.cantidadOro;
}
int getCantidadPlatino(Comanda &comanda){
    return comanda.cantidadPlatino;
}

void setCantidadCarbon(Comanda &comanda,int cantidad){
    comanda.cantidadCarbon=cantidad;
}
void setCantidadBronce(Comanda &comanda,int cantidad){
    comanda.cantidadBronce=cantidad;
}
void setCantidadPlata(Comanda &comanda,int cantidad){
    comanda.cantidadPlata=cantidad;
}
void setCantidadOro(Comanda &comanda,int cantidad){
    comanda.cantidadOro=cantidad;
}
void setCantidadPlatino(Comanda &comanda,int cantidad){
    comanda.cantidadPlatino=cantidad;
}


