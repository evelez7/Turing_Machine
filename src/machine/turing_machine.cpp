/** \file turing_machine.cpp */
#include "turing_machine.h"

Turing_Machine::Turing_Machine(const std::shared_ptr<Program> &program) : program(program), tape(program->get_arguments()) {
    if (this->program->get_arguments().empty()) {
        this->tape.write(this->program->get_blank_symbol());
    }
}

void Turing_Machine::execute() {
    auto current_program = this->program;
    this->config = Configuration(this->tape, current_program->get_initial_state());
    this->head = this->tape.get_first();
    auto halting_states = current_program->get_halting_states();
    if (head->is_blank()) {
        head->write_to_cell(current_program->get_blank_symbol());
    }
    while (std::find(halting_states.begin(), halting_states.end(), this->config.get_state()) != halting_states.end()) {
        auto current_symbol = head->get_content();
    }
}

void Turing_Machine::write_to_tape(const std::string &to_write) {
    this->head->write_to_cell(to_write);
}

void Turing_Machine::print_tape() const {
    this->tape.print();
}
