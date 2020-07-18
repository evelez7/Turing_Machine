#include "cell.h"

Cell::Cell(const std::string &to_write) {
    this->content = to_write;
}

void Cell::write_to_cell(const std::string &to_write) {
    this->content = to_write;
}

std::string Cell::get_content() const {
    return this->content;
}