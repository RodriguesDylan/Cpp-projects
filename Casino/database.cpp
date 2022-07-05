// headers
#include "database.hpp"
#include <ios>
#include <string>

string *Database::ProcessLine(string line, string *array)
{
  // line is in the form : "username=foo balance=foo"
  // space is the delimiter, we split on it
  string delimiter = " ";
  size_t pos = 0;
  pos = line.find(delimiter);
  array[0] = line.substr(0, pos);
  array[1] = line.substr(pos);
  return array;
}

string Database::eraseSubStr(string &mainStr, string toErase)
{
  size_t pos = mainStr.find(toErase);

  if (pos != string::npos)
  {
    mainStr.erase(pos, toErase.length());
  }
  return mainStr;
}

void Database::Logindb()
{
  fstream file("database.txt");
  string userName = "";
  string line = "";
  string usernameBalance[2]; // contain 2 strings, first is in the form "username=[name]" and second is "balance=[amount]"
  bool control = false;

  cout << "What's your name?\n";
  cin >> userName;
  while (getline(file, line) && !control)
  {
    // process line
    ProcessLine(line, usernameBalance);
    if (("username=" + userName) == usernameBalance[0])
    {
      control = true;
      cout << "Welcome " << userName << ".\t"
           << "Your balance is " << usernameBalance[1] << "$.\n";
    }
  }
  if (!control)
  {
    fstream file("database.txt", ios::app);
    cout << "Looks like you are new to the Casino!\n"
         << "We will create your account with this username and offer you "
            "100$!\n";
    file << "username=" + userName + " balance=100\n";
    balance = 100;
    file.close();
  }
  else
  {
    balance = std::stoi(eraseSubStr(usernameBalance[1], "balance="));
  }
  file.close();

  // this keep track of the user and his balance to update it in real time
  user = userName;

  cout << "user =" << userName << " balance=" << balance << "\n";
}

void Database::clearDB()
{
  ofstream file;
  file.open("database.txt", std::ofstream::out | std::ofstream::trunc);
  file.close();
}

void Database::initDB()
{
  fstream file("database.txt", ios::app);
  file << "username=user balance=100\n";
  file << "username=admin balance=1000000\n";
  file.close();
}

void Database::updateDB()
{
  fstream fileToUpdate("database.txt");
  fstream fileTarget("database2.txt", ios::app);

  string line = "";
  string usernameBalance[2];

  // while loop will copy entire file to fileTarget and modify the needed line by the new balance value
  while (getline(fileToUpdate, line))
  {
    // process line
    ProcessLine(line, usernameBalance);
    if (("username=" + user) == usernameBalance[0])
    {
      fileTarget << "username=" + user << " balance=" + std::to_string(balance) + "\n";
    }
    else
    {
      fileTarget << line + "\n";
    }
  }
  remove("database.txt");
  rename("database2.txt", "database.txt");
}

bool Database::exists_test(const std::string &name)
{
  ifstream f(name.c_str());
  return f.good();
}
