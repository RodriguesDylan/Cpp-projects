// headers
#include "database.hpp"
#include <ios>
#include <string>

string *Database::ProcessLine(string line, string *array) {
  // line is in the form : "username=foo balance=foo"
  string delimiter = " ";
  size_t pos = 0;
  pos = line.find(delimiter);
  array[0] = line.substr(0, pos);
  array[1] = line.substr(pos);
  return array;
}

void Database::Logindb() {
  fstream file("database.txt");
  string userName = "";
  string line = "";
  string usernameBalance[2];
  bool control = false;

  cout << "What's your name?\n";
  cin >> userName;
  while (getline(file, line) && !control) {
    // process line
    ProcessLine(line, usernameBalance);
    if (("username=" + userName) == usernameBalance[0]) {
      control = true;
      cout << "Welcome " << userName << ".\t"
           << "Your balance is " << usernameBalance[1] << "$.\n";
    }
  }
  if (!control) {
    fstream file("database.txt", ios::app);
    cout << "Looks like you are new to the Casino!\n"
         << "We will create your account with this username and offer you "
            "100$!\n";
    file << "username=" + userName + " balance=100\n";
    file.close();
  }
  file.close();
}

void Database::clearDB() {
  ofstream file;
  file.open("database.txt", std::ofstream::out | std::ofstream::trunc);
  file.close();
}

void Database::initDB() {
    fstream file("database.txt", ios::app);
    file << "username=user balance=100\n";
    file << "username=admin balance=1000000\n";
    file.close();
}