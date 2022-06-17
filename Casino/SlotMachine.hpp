// guard
#ifndef SLOTMACHINE_H_
#define SLOTMACHINE_H_
// headers
#include "casino.hpp"

class SlotMachine {
public:
  SlotMachine(){};
  ~SlotMachine(){};

  void StartMessage();
  void Rules();
  void GameSlot();
  void GameLoop(SlotMachine sm);
};

#endif