#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;

void render() {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_CreateWindowAndRenderer(500,500,SDL_WINDOW_RESIZABLE,&window,&renderer);

  while (1) {
    SDL_WaitEvent(&e);
  }
}