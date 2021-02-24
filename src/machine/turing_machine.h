/** \file turing_machine.h */
#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H
#include <memory>
#include <map>
#include <string>
#include "cell.h"
#include "configuration.h"
#include "tape.h"
#include "../program.h"

class Turing_Machine
{
private:
  Tape tape;
  std::shared_ptr<Cell> head;
  std::shared_ptr<Program> const &program;
  Configuration config;
  std::shared_ptr<Cell> move_head(const std::map<std::string, std::string> &);

public:
  /**
     * \brief Construct using Program
     */
  Turing_Machine(const std::shared_ptr<Program> &current_program);
  void execute();
  void write_to_tape(const std::string &);
  void print_tape() const;
};

#endif //TURING_MACHINE_H
