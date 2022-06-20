// headers
#include "casino.hpp"
#include "database.hpp"

// --- CASINO GAME ---
// by Dylan RODRIGUES - 2022

int main() {
  std::cout << "-- BEGIN --\n";

  Casino gameInstance;
  Database db;
  int gameNumber = 1;

  if (!db.exists_test("database.txt")) {
    cout << "New database created!\n";
    db.initDB();
  }

  gameInstance.Welcome();

  while (gameNumber > 0) {

    gameNumber = gameInstance.GameSelect();
    gameInstance.SelectedGameProcess(gameNumber);
  }

  std::cout << "-- END --\n";
}
