// headers
#include "casino.hpp"

// --- CASINO GAME ---
// by Dylan RODRIGUES - 2022

int main() {
  std::cout << "-- BEGIN --\n";

  Casino gameInstance;
  int gameNumber;

  gameInstance.Welcome();

  while (gameNumber>0) {
    
    gameNumber = gameInstance.GameSelect();
    gameInstance.SelectedGameProcess(gameNumber);
  }

  std::cout << "-- END --\n";
}
