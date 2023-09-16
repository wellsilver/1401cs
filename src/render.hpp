#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

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

void button(int posx,int posy,int sizex,int sizey) {
  SDL_Rect button;
  button.x = posx;
  button.y = posy;
  button.h = sizey;
  button.w = sizex;
  if (SDL_PointInRect(&mouse,&button)) {
    SDL_SetRenderDrawColor(renderer, 150,150,150,SDL_ALPHA_OPAQUE);
  } else {
    SDL_SetRenderDrawColor(renderer, 100,100,100,SDL_ALPHA_OPAQUE);
  }
  SDL_RenderFillRect(renderer, &button);
}

void render() {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_CreateWindowAndRenderer(500,500,SDL_WINDOW_RESIZABLE,&window,&renderer);

  SDL_WaitEvent(&e); // wait for a event that main.cpp sends (so we arent just trying to read random memory)

  while (1) {
    switch (e.type) {
      case SDL_QUIT:
        SDL_DestroyWindow(window);
        return;
      break;
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderGetViewport(renderer, &viewport);
    SDL_GetMouseState(&mouse.x,&mouse.y);
    
    button(getx(0.1),gety(0.1),getx(0.1),gety(0.1));
    
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);

    SDL_WaitEvent(&e);
  }
}