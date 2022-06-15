// guard
#ifndef CASINO_H_
#define CASINO_H_
// libraries
#include <cstdlib>
#include <iostream>

using namespace std;

class Casino {

public:
  Casino(){};
  ~Casino(){};

  void Welcome();
  int GameSelect();
  void SelectedGameProcess(int gameNumber);
};

class RandomNumberGuesser {

public:
  RandomNumberGuesser(){};
  ~RandomNumberGuesser(){};

  void StartMessage();
  void Rules();
  void GameRNG();
};

#endif
