#ifndef MAPA_H
#define MAPA_H
#include <SDL.h>

typedef struct{
    int id;
    int posX;
    int posY;
    bool ocupado;
}Bloque;

typedef struct{
    int width;
    int heigth;
    int col;
    int fil;
    Bloque bloques[][];
    SDL_Rect destino;
    SDL_Texture* textura;

}Mapa;



void crearMapa(Mapa &mapa,SDL_Renderer *renderer);
void dibujarMapa(Mapa &mapa,SDL_Renderer *renderer);
void destruirMapa(Mapa &mapa);
void crearBloque(Bloque &bloque,int fil,int col);
void destruirBloque(Bloque &bloque);

#endif // MAPA_H
