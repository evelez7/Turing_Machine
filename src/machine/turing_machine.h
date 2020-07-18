/** \file turing_machine.h */
#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H
#include <memory>
#include <nlohmann/json.hpp>
#include "configuration.h"
#include "tape.h"
#include "../program.h"

using json = nlohmann::json;

class Turing_Machine {
private:
    Tape tape;
    std::shared_ptr<Cell> head;
    std::shared_ptr<Program> const& program;
    Configuration config;
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
