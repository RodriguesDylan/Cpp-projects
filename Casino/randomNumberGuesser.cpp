#include "randomNumberGuesser.hpp"

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
