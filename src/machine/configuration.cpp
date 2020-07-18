
#include "configuration.h"
#include <list>
#include <utility>

Configuration::Configuration(const Tape &tape, std::string initial_state) : state(std::move(initial_state)) {
    this->state = initial_state;
    this->cell = tape.get_first();
    if (tape.get_size() == 1) {
        this->active_tape_left.emplace_back(new Cell());
        this->active_tape_right.emplace_back(new Cell());
    }
}

Configuration::Configuration() = default;

std::string Configuration::get_state() {
    return this->state;
}