#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;

void render() {
  if (SDL_CreateWindowAndRenderer(100, 100, SDL_WINDOW_RESIZABLE, &window, &renderer) == -1) {
    return;
  }

  SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  SDL_RenderPresent(renderer);

  while (true) {
    SDL_WaitEvent(&e);
    if (e.type == SDL_QUIT) {
      return;
    }
    
    SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
  }
}