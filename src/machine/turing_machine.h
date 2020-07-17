//
// Created by Erick Velez on 2019-07-27.
//
#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

#include "configuration.h"
#include "tape.h"

class Turing_Machine {
private:
    Tape machine_tape;

public:
    Turing_Machine();
    ~Turing_Machine();
};

#endif //TURING_MACHINE_H
