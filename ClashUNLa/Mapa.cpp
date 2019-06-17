#include "Mapa.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Bloque.h"

void crearMapa(Mapa &mapa,SDL_Renderer *renderer){
    mapa.ancho = 800;
    mapa.alto = 600;
    mapa.col = mapa.ancho/40;
    mapa.fil = mapa.alto/40;
    mapa.textura = IMG_LoadTexture(renderer,"img/suelo.png");
    mapa.destino.x = 0;
    mapa.destino.y = 0;
    mapa.destino.w = mapa.ancho;
    mapa.destino.h = mapa.alto;
    //mapa.bloques = crearBloques(mapa.fil,mapa.col);

    int id = 1;
    for(int i = 0 ; i<mapa.fil;i++){
        for(int j = 0;j< mapa.col;j++){
            mapa.bloques[i][j]=crearBloque(id,i+1,j+1);
            id++;
        }
    }
}
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer){
    SDL_RenderCopy(renderer,mapa.textura,NULL,&mapa.destino);

}
void destruirMapa(Mapa &mapa){
    SDL_DestroyTexture(mapa.textura);
}

void mostrarBloquesMapa(Mapa &mapa){
    for(int i = 0;i<mapa.fil;i++){
        for(int j=0 ;j<mapa.col;j++ ){
            mostrarBloque(mapa.bloques[i][j]);
        }
    }
}


