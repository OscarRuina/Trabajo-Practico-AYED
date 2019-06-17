#include "Mina.h"
#include <SDL.h>
#include <SDL_image.h>

void crearMina(Mina &mina,SDL_Renderer *renderer){
    mina.ancho =40;
    mina.largo =40;
    mina.textura = IMG_LoadTexture(renderer,"img/mina.png");

    mina.destino.h=40;
    mina.destino.w=40;
    mina.destino.x=0;
    mina.destino.y=0;

}

void generarPosicion(Mina &mina);
void crearCajas(Mina &mina){


}
void eliminarMina(Mina &mina);
