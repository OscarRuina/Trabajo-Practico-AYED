#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"

class game
{
private:
    bool Running;
    SDL_Window * window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    SDL_Rect cuadradito;
public:
    game();
    //virtual ~game();
    int OnExecute();
    void set_pixel(int x, int y, unsigned int color);
    void set_color(unsigned int color);
    void draw_something();
    bool OnInit();
    bool LoadContent();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void Cleanup();

};
#endif // GAME_H_INCLUDED
