// libraries

// headers
#include "casino.hpp"
#include "SlotMachine.hpp"
#include "randomNumberGuesser.hpp"

// Casino methods
void Casino::Welcome() { cout << "Welcome to our Casino!\n"; }

int Casino::GameSelect() {
  int chosenGame = 0; // game identifier
  cout << "Select a game by entering a number :\n"
       << "1 : RandomNumberGuesser      2 : SlotMachine"
       << "\n"
       << "0 : Leave the casino.\n";
  do {
    cin >> chosenGame;
    if (chosenGame < 0 || chosenGame > 2) {
      cout << "Must be a valid number!\n";
    }
  } while (chosenGame < 0 || chosenGame > 2);

  return chosenGame;
}

void Casino::SelectedGameProcess(int gameNumber) {
  RandomNumberGuesser rng;
  SlotMachine sm;
  switch (gameNumber) {
  case 0:
    cout << "Goodbye!\n";
    break;
  case 1:
    rng.StartMessage();
    rng.Rules();
    rng.GameRNG();
    break;
  case 2:
    sm.GameLoop(sm);
    break;
  }
}

