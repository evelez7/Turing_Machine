#include "tape.h"
#include "cell.h"
#include <iostream>

Tape::Tape(const std::vector<std::string> &to_write) {
    this->cell_list = std::list<Cell>();
    for (const auto& symbol : to_write) {
        this->cell_list.emplace_back(Cell(symbol));
    }
}

void Tape::print() const {
    for (int i = 0; i < this->cell_list.size(); ++i) {
        printf("=====");
    }
    printf("\n");

    for (auto const& current_cell : this->cell_list) {
        printf("| ");
        std::cout << current_cell.get_content();
        printf(" |");
    }
}

