// header
#include "SlotMachine.hpp"
#include <chrono>
#include <cstdlib>

void SlotMachine::StartMessage() { cout << "Starting SlotMachine !\n"; }

void SlotMachine::Rules() {
  cout << "Roll the machine and align 3 symbols to win.\n"
       << "[$] [$] [$] = Jackpot       "
       << "[a] [a] [a] = Win 2xbet\n"
       << "[b] [b] [b] = Win 5x bet\n";
}

void SlotMachine::GameSlot() {
  string symbols = "$ab";
  string slotResult = "";
  cout << "---------------\n";

  for (int i = 0; i < 3; ++i) {
    // nanosecond time for the random number generator
    auto now = std::chrono::high_resolution_clock::now();
    auto now_ns = std::chrono::time_point_cast<std::chrono::nanoseconds>(now);
    auto epoch = now_ns.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::nanoseconds>(epoch);
    unsigned int intedValue = value.count();

    srand(intedValue);
    slotResult.push_back(symbols[rand() % 3]);
  }
  cout << "| [" << slotResult[0] << "] "
       << "[" << slotResult[1] << "] "
       << "[" << slotResult[2] << "] |\n";
  cout << "---------------\n";
}

void SlotMachine::GameLoop(SlotMachine sm) {
  bool update = false;  //loop controller
  string answer = "";
  sm.StartMessage();
  sm.Rules();
  do {
    sm.GameSlot();
    cout << "Continue? (y/n)\n";
    cin >> answer;
    if (answer == "n") {
      update = false;
    } else {
      update = true;
    }
  } while (update);
}