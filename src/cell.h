#ifndef CELL_H
#define CELL_H

class Cell {
private:
    char* content;
public:
    Cell(char* content);
    Cell(char& content);
    char getContent();
    char writeContent(char& contentToWrite);
};

#endif