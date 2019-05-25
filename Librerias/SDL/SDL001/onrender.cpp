#include"game.h"
void game::OnRender()
{
    int w;
    int h;
    this->set_color(0x0);
    SDL_RenderClear(this->renderer);

    SDL_GetWindowSize(this->window,
                       &w,
                       &h);
    this->cuadradito.x+=10;
    if(this->cuadradito.x>=w){
        this->cuadradito.x=0;
    }

    this->set_color(0x00ff00);
    SDL_RenderFillRect(this->renderer,
                       &cuadradito);
    SDL_RenderPresent(this->renderer);// actualiza el dibujo
}
