// libraries

// headers
#include "casino.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

// Casino methods
void Casino::Welcome() { cout << "Welcome to our Casino!\n"; }

int Casino::GameSelect() {
  int chosenGame = 0;
  cout << "Select a game by entering a number :\n"
       << "1 : RandomNumberGuesser"
       << "\n"
       << "0 : Leave the casino.\n";
  do {
    cin >> chosenGame;
    if (chosenGame < 0 || chosenGame > 1) {
      cout << "Must be a valid number!\n";
    }
  } while (chosenGame < 0 || chosenGame > 1);

  return chosenGame;
}

void Casino::SelectedGameProcess(int gameNumber) {
  switch (gameNumber) {
  case 0:
    cout << "Goodbye!\n";
    break;
  case 1:
    RandomNumberGuesser rng;
    rng.StartMessage();
    rng.Rules();
    rng.GameRNG();
    break;
  }
}

// RandomNumberGuesser methods
void RandomNumberGuesser::StartMessage() {
  cout << "Starting RandomNumberGuesser !\n";
}
void RandomNumberGuesser::Rules() {
  cout << "The rules are :\n"
       << "    1. Choose a number between 0 and 10.\n"
       << "    2. If you guessed right, you win!\n";
}
void RandomNumberGuesser::GameRNG() {
  srand(time(nullptr));
  int number = rand() % 10;
  int guessedNumber;

  // validity loop
  do {
    cout << "Choose a number between 0 and 10 : \n";
    cin >> guessedNumber;

    if (guessedNumber > 10 || guessedNumber < 0) {
      cout << "Must be between 0 and 10 ! \n";
    }

  } while (guessedNumber > 10 || guessedNumber < 0);

  // result
  if (guessedNumber == number) {
    cout << "You win!\n";
  } else {
    cout << "You lose...\n"
         << "The number was " << number << "!\n";
  }
}
