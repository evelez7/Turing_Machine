#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
private:
    std::string content;
public:
    Cell(const std::string &);
    void write_to_cell(const std::string &);
    std::string get_content() const;
};

#endif