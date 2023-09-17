#ifndef __render
#define __render

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <thread>
using std::thread;

#include "1401.hpp"

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Event e;

SDL_Rect viewport;
SDL_Point mouse;

inline int getx(float pos) {
  return viewport.w * pos;
}

inline int gety(float pos) {
  return viewport.h * pos;
}

void button(int posx,int posy,int sizex,int sizey,bool toggled) {
  Uint8 r,g,b;
  SDL_Rect button;
  SDL_Rect buttonoutfillreverse;
  button.x = posx;
  button.y = posy;
  button.h = sizey;
  button.w = sizex;
  buttonoutfillreverse = button;
  buttonoutfillreverse.y += SDL_ceil((button.h*0.1)/2);
  buttonoutfillreverse.x += SDL_ceil((button.w*0.05)/2);
  buttonoutfillreverse.h -= (button.h*0.1);
  buttonoutfillreverse.w -= (button.w*0.05);
  SDL_GetRenderDrawColor(renderer,&r,&g,&b,NULL);
  if (toggled) {
    SDL_SetRenderDrawColor(renderer, r*1.5,g*1.5,b*1.5, SDL_ALPHA_OPAQUE);
  } else {
    SDL_SetRenderDrawColor(renderer, r,g,b, SDL_ALPHA_OPAQUE);
  }
  SDL_RenderFillRect(renderer, &button);
  if (SDL_PointInRect(&mouse,&button)) {
    SDL_SetRenderDrawColor(renderer, r*1.3,g*1.3,b*1.3, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &buttonoutfillreverse);
  } else {
    SDL_SetRenderDrawColor(renderer, r*0.7,g*0.7,b*0.7, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &buttonoutfillreverse);
  }
}

void controlpanel() {
  SDL_CreateWindowAndRenderer(300,400,0,&window,&renderer);

  SDL_SetWindowMinimumSize(window,200,300);
  SDL_SetWindowTitle(window,"Console");

  SDL_WaitEvent(&e); // wait for a event that main.cpp sends (so we arent just trying to read random memory)

  while (1) {
    switch (e.type) {
      case SDL_QUIT:
        SDL_DestroyWindow(window);
        return;
      break;
    }
    SDL_SetRenderDrawColor(renderer,50,50,50,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderGetViewport(renderer, &viewport);
    SDL_GetMouseState(&mouse.x,&mouse.y);
    
    SDL_SetRenderDrawColor(renderer,0,100,0,SDL_ALPHA_OPAQUE);
    button(getx(0.1),gety(0.8),getx(0.2),gety(0.05),false);
    SDL_SetRenderDrawColor(renderer,100,100,100,SDL_ALPHA_OPAQUE);
    button(getx(0.4),gety(0.8),getx(0.2),gety(0.05),false);
    SDL_SetRenderDrawColor(renderer,100,0,0,SDL_ALPHA_OPAQUE);
    button(getx(0.7),gety(0.8),getx(0.2),gety(0.05),false);

    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);

    SDL_WaitEvent(&e);
  }
}

void render() {
  SDL_Init(SDL_INIT_EVERYTHING);

  auto v = thread(controlpanel);
  
  v.join();
}

#endif