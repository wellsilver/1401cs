#include <iostream>
#include <thread>

#include "1401.hpp"

#include "render.hpp"

using namespace std;
using std::thread;

int main() {

  auto th = thread(render);

  computerrun();

  th.join();

  return 0;
}