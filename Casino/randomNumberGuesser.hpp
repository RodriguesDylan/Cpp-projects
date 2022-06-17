//guard
#ifndef RNG_H_
#define RNG_H_
//header
#include "casino.hpp"

class RandomNumberGuesser {
public:
  RandomNumberGuesser(){};
  ~RandomNumberGuesser(){};

  void StartMessage();
  void Rules();
  void GameRNG();
  void GameLoop(RandomNumberGuesser rng);
};

#endif