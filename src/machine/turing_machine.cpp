/** \file turing_machine.cpp */
#include "turing_machine.h"
#include <iostream>

Turing_Machine::Turing_Machine(const std::shared_ptr<Program> &program) : program(program), tape(program->get_arguments()) {
    if (this->program->get_arguments().empty()) {
        this->tape.write(this->program->get_blank_symbol(), true);
    }
}

void Turing_Machine::execute() {
    auto current_program = this->program;
    this->config = Configuration(this->tape, current_program->get_initial_state());
    this->head = this->tape.get_first();
    if (head->is_blank()) {
        head->write_to_cell(current_program->get_blank_symbol());
    }

    auto halting_states = current_program->get_halting_states();
    while (std::find(halting_states.begin(), halting_states.end(), this->config.get_state()) == halting_states.end()) {
        auto current_symbol = head->get_content();
        for (const auto &transition : this->program->get_function_table()) {
            if (transition.at("current_symbol") == current_symbol && transition.at("current_state") == this->config.get_state()) {
                // correct transition
                this->move_head(transition);
            }
        }
    }
}

void Turing_Machine::write_to_tape(const std::string &to_write) {
    this->head->write_to_cell(to_write);
}

void Turing_Machine::print_tape() const {
    this->tape.print();
}

std::shared_ptr<Cell> Turing_Machine::move_head(const std::map<std::string, std::string> &transition) {
    auto current_cell = this->head;
    auto next_cell = this->head->get_next_cell();
    auto previous_cell = this->head->get_previous_cell();

}
