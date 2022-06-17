// guard
#ifndef CASINO_H_
#define CASINO_H_
// libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Casino {
public:
  Casino(){};
  ~Casino(){};

  void Welcome();
  int GameSelect();
  void SelectedGameProcess(int gameNumber);
};



#endif