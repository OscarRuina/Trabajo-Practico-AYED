#include "Mapa.h"
#include <SDL.h>
#include <SDL_image.h>

void crearMapa(Mapa &mapa,SDL_Renderer *renderer){
    mapa.width = 800;
    mapa.heigth = 600;
    mapa.col = 40;
    mapa.fil = 30;
    mapa.textura = IMG_LoadTexture(renderer,"img/suelo_4.png");
    mapa.destino.x = 0;
    mapa.destino.y = 0;
    mapa.destino.h = mapa.heigth;
    mapa.destino.w = mapa.width;
    //mapa.bloques = crearBloques(mapa.fil,mapa.col);
}
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer){
    SDL_RenderCopy(renderer,mapa.textura,NULL,&mapa.destino);

}
void destruirMapa(Mapa &mapa){
    SDL_DestroyTexture(mapa.textura);
}

/*Bloque[][] crearBloques(int fil,int col){

}*/
void destruirBloque(Bloque &bloque){


}
