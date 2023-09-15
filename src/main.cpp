#include <iostream>
#include <thread>

#include "1401.hpp"
#include "render.hpp"

using namespace std;
using std::thread;

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  
  // make the renderer's thread
  auto rthread = thread(render); // why exactly does this work?
  rthread.detach();

  // make the 1401's thread
  auto cthread = thread(mainframe_1401::run); // still confused on why making a thread this way is working
  cthread.detach();
  

  return 0;
}