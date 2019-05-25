#include"game.h"

game::game()
{
    window = NULL;
    Running = true;
}




void game::set_color(unsigned int color){
 SDL_SetRenderDrawColor(this->renderer,
                           color >>16 &0xff,
                           color >>8 &0xff,
                           color  &0xff,
                           color >>24 &0xff);
}

void game::set_pixel(int x, int y, unsigned int color){

    SDL_SetRenderDrawColor(this->renderer,
                           color >>16 &0xff,
                           color >>8 &0xff,
                           color  &0xff,
                           color >>24 &0xff);
    SDL_RenderDrawPoint(this->renderer,
                        x,
                        y);

}


void game::draw_something(){

    cuadradito.h=10;
    cuadradito.w=10;
    cuadradito.y=100;
    cuadradito.x=50;

    this->set_pixel(10,10,0xff0000);


    this->set_color(0x00ff00);
    SDL_RenderFillRect(this->renderer,
                       &cuadradito);



    SDL_RenderPresent(this->renderer);// actualiza el dibujo

}

int game::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }



    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    Cleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    game theGame;

    return theGame.OnExecute();
}
