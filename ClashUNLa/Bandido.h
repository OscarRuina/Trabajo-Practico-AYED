#ifndef Bandido_h
#define Bandido_h
#include <SDL.h>
typedef struct{
  int f;
  int c;
  SDL_Texture *imagen;
  SDL_Rect rectImagen;
}Bandido;

void crearBandido(Bandido &bandido,SDL_Renderer *renderer);
void dibujarBandido(Bandido &bandido,SDL_Renderer *renderer);
void destruirBandido(Bandido &bandido);
void cargarVariablesBandido(Bandido &bandido);
void setFila(Bandido &bandido,int f);
void setColumna(Bandido &bandido,int c);
int getFila(Bandido &bandido);
int getColumna(Bandido &bandido);
#endif // Bandido_h
