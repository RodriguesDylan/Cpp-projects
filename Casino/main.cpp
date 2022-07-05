// headers
#include "casino.hpp"
#include "database.hpp"

// --- CASINO GAME ---
// by Dylan RODRIGUES - 2022

int main()
{
  std::cout << "-- BEGIN --\n";

  Casino gameInstance; // game
  Database db;         // database
  int gameNumber = 1;

  if (!db.exists_test("database.txt"))
  {
    // create db if not already created
    cout << "New database created!\n";
    db.initDB();
  }

  db.Logindb();
  gameInstance.Welcome();

  int &balance = db.balance;

  while (gameNumber > 0)
  {
    // game loop
    gameNumber = gameInstance.GameSelect();
    gameInstance.SelectedGameProcess(gameNumber);
  }

  db.updateDB();

  std::cout << "-- END --\n";
}
