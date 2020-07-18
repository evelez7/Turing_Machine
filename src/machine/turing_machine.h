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
    std::shared_ptr<Program> const& current_program;
public:
    /**
     * \brief Construct using Program 
     */
    Turing_Machine(const std::shared_ptr<Program> &current_program);
    void execute();
    void write_to_tape(const std::vector<std::string> &);
    void print_tape();
};

#endif //TURING_MACHINE_H
