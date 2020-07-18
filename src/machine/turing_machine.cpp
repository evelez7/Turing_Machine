/** \file turing_machine.cpp */
#include "turing_machine.h"

Turing_Machine::Turing_Machine(const std::shared_ptr<Program> &current_program) : current_program(current_program), tape(current_program->get_arguments()) {}

void Turing_Machine::execute() {

}

void Turing_Machine::write_to_tape(const std::vector<std::string> &to_write) {

}

void Turing_Machine::print_tape() {
    this->tape.print();
}
