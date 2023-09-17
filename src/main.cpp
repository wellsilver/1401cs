#include <iostream>
#include <thread>

#include "1401.hpp"
#include "render.hpp"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

using namespace std;
using std::thread;

int main() {
  mainframe_1401 comp;

  auto th = thread(render, comp);

  // send a event that gets ignored to the renderer to render a frame
  SDL_Event fakeevent;
  fakeevent.type = SDL_FINGERMOTION;
  SDL_PollEvent(&fakeevent);

  comp.run();
  th.join();

  SDL_Quit();
  return 0;
}