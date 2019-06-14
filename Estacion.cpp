#include "Estacion.h"
/*Implementacion de Primitivas*/
void crearEstacion(Estacion &estacion,int f,int c,int anchoCasillero,int altoCasillero,SDL_Renderer *renderer){
    estacion.f = f;
    estacion.c = c;
    estacion.imagen = IMG_LoadTexture(renderer,"img/estacion.png");
    estacion.rectImagen.y = f * altoCasillero;
    estacion.rectImagen.x = c * anchoCasillero;
    estacion.rectImagen.h = altoCasillero;
    estacion.rectImagen.w = anchoCasillero;

}

void dibujarEstacion(Estacion &estacion,SDL_Renderer *renderer){
    SDL_RenderCopy(renderer,estacion.imagen,NULL,&(estacion.rectImagen));
}

void destruirEstacion(Estacion &estacion){
    SDL_DestroyTexture(estacion.imagen);
}
