#ifndef CELL_H
#define CELL_H

class Cell {
private:
    char* content;
public:
    Cell(char* content);
    Cell(char& content);
    char get_content();
    char write_content(char const&);
};

#endif