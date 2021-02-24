#ifndef TURING_MACHINE_TAPE_H
#define TURING_MACHINE_TAPE_H

#include "cell.h"
#include <list>
#include <vector>
#include <string>

class Tape
{
private:
  std::list<std::shared_ptr<Cell>> cell_list;
  int size;

public:
  explicit Tape(const std::vector<std::string> &);
  void print() const;
  int get_size() const;
  std::shared_ptr<Cell> get_first() const;
  void write(const std::string &);
  void write(const std::string &, bool);
};

#endif //TURING_MACHINE_TAPE_H
