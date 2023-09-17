// simulation script
#ifndef __1401
#define __1401

#include <chrono>
#include <stdint.h>
#include <string>
#include <list>

using std::string;
using std::list;

struct word1401 {
  char mem;
  // ^ store the character in its actual string form. 
  // I cant find any resources on how the 1401 stored its bits internally, 
  // and the proggraming guides table is not explained
  bool marked;
};

class mainframe_1401 {
  public:
    void run();

    list<word1401> memory; // size is either 1400, 4000, or 16000
    string dumpsection(int, int);
};

void mainframe_1401::run() {
  
}

string mainframe_1401::dumpsection(int start, int end) {
  string ret;
  for (auto it = memory.begin(); it != memory.end(); ++it){
    ret += it->mem;
  }
  return ret;
}
// as a c proggramer who just started learning c++, why does mainframe_1401::dumpsection look so ugly?

void computerrun() {
  auto c = new mainframe_1401;
  c->run();
}

#endif