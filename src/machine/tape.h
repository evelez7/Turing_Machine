#ifndef TURING_MACHINE_TAPE_H
#define TURING_MACHINE_TAPE_H

#include "cell.h"
#include <list>
#include <vector>
#include <string>

class Tape {
private:
    std::list<Cell> cell_list;
public:
    explicit Tape(const std::vector<std::string>&);

    void print() const;
};

#endif //TURING_MACHINE_TAPE_H
