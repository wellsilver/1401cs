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
  bool marked;
  // ^ store the character in its actual string form. 
  // I cant find any resources on how the 1401 stored its bits internally, other than with 6 bits,
  // and the proggraming guides table is not explained
};

class mainframe_1401 {
  public:
    void run();

    bool ctrlpnl_checkreset;

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

#endif