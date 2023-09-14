// simulation script

#include <stdint.h>
#include <string>
#include <list>

using std::string;
using std::list;

struct word1401 {
  uint16_t mem; // ignore last 4 bits lol. I believe each spot in memory is 12 bits large
  bool marked;
};

class mainframe_1401 {
  public:
    void init(int);

    list<word1401> memory; // size is either 1400, 4000, or 16000
    string dumpsection(int, int);
    string int_tostr(int);
};

void mainframe_1401::init(int memorysize) {

}

string mainframe_1401::dumpsection(int start, int end) {
  string ret;
  for (auto it = memory.begin(); it != memory.end(); ++it){
    ret += int_tostr(it->mem);
  }
  return ret;
}

string mainframe_1401::int_tostr(int v) {
  switch (v) {
    case 0:
      return " ";
    break;
    case 1:
      return "&";
    break;
    case 2:
      return "-";
    break;
    case 4:
      return "0";
    break;
    case 8:
      return "1";
    break;
    case 16:
      return "2";
    break;
    case 32:
      return "3";
    break;
    case 64:
      return "4";
    break;
    case 128:
      return "5";
    break;
    case 256:
      return "6";
    break;
    case 512:
      return "7";
    break;
    case 1024:
      return "8";
    break;
    case 2048:
      return "9";
    break;
  };
  return " ";
}