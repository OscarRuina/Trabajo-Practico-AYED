#include "Mina.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Moneda.h"
#include <iostream>
#include <fstream>

using namespace std;

void crearMina(Mina &mina,SDL_Renderer *renderer,int fil,int col,int tipo){
    mina.fil = fil;
    mina.col = col;
    mina.tipo= traerTipo(tipo);
    cargarCajas(mina);
    mina.imagen = IMG_LoadTexture(renderer,"img/mina.png");

}

void cargarCajas(Mina &mina){

    //mina.cajas[] = ;
  /*  ifstream fin("Minas.txt");
    for(int i = 0;i < 5;i++){
        fin>>mina.cajas[i];
    }*/
}



void dibujarMina(Mina &mina,SDL_Renderer* renderer){

    mina.rectImg.x = mina.col*40;
    mina.rectImg.y = mina.fil*40;
    mina.rectImg.w = 40;
    mina.rectImg.h = 40;
    SDL_RenderCopy(renderer,mina.imagen,NULL,&(mina.rectImg));

}
void eliminarMina(Mina &mina);
