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
  string answer;
  int guessedNumber;

  // validity loop
  do {
    cout << "Choose a number between 0 and 10 : \n";
    cin >> answer;
    guessedNumber = stoi(answer);

    if (guessedNumber > 10 || guessedNumber < 0) {
      cout << "Must be between 0 and 10 ! \n";
      guessedNumber = -1;
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

void RandomNumberGuesser::GameLoop(RandomNumberGuesser rng){
  bool update = false;  //loop controller
  string answer = "";
  rng.StartMessage();
  rng.Rules();
  do {
    rng.GameRNG();
    cout << "Continue? (y/n)\n";
    cin >> answer;
    if (answer == "n") {
      update = false;
    } else {
      update = true;
    }
  } while (update);
  
}
