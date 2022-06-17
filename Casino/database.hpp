// guard
#ifndef DB_H_
#define DB_H_
// headers
#include "casino.hpp"
// libs
#include <fstream>
#include <vector>

class Database {
public:
  Database() {}
  ~Database() {}

  string *ProcessLine(string line, string *array);
  void initDB();
  void Logindb();
  void clearDB();
};

#endif