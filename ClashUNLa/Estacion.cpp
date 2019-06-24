#include "Estacion.h"
#include "Bloque.h"
#include <iostream>
#include <fstream>

using namespace std;
/*Implementacion de Primitivas*/
void crearEstacion(Estacion &estacion,SDL_Renderer *renderer){
    cargarVariables(estacion);
    estacion.imagen = IMG_LoadTexture(renderer,"img/estacion.png");

}

void cargarVariables(Estacion &estacion){
    ifstream fin("Estacion.txt");
    fin>>estacion.f>>estacion.c;
}
void dibujarEstacion(Estacion &estacion,SDL_Renderer *renderer){
    estacion.rectImagen.x = estacion.c*40;
    estacion.rectImagen.y = estacion.f*40;
    estacion.rectImagen.w = 40;
    estacion.rectImagen.h = 40;
    SDL_RenderCopy(renderer,estacion.imagen,NULL,&(estacion.rectImagen));
}

void destruirEstacion(Estacion &estacion){
    SDL_DestroyTexture(estacion.imagen);
}
