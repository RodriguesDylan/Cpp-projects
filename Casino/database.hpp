// guard
#ifndef DB_H_
#define DB_H_
// headers
#include "casino.hpp"
// libs
#include <fstream>
#include <vector>

class Database
{
public:
  string user;
  int balance;

  Database() {}
  ~Database() {}

  string *ProcessLine(string line, string *array);
  string eraseSubStr(string &mainStr, string toErase);
  void initDB();
  void Logindb();
  void clearDB();
  void updateDB();
  bool exists_test(const std::string &name);
};

#endif
