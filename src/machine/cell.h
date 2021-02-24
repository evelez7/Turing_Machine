#ifndef CELL_H
#define CELL_H

#include <string>
#include <memory>

class Cell
{
private:
  std::string content;
  std::shared_ptr<Cell> previous;
  std::shared_ptr<Cell> next;
  bool blank;

public:
  Cell(const std::string &);
  Cell(const std::string &, bool);
  Cell();
  ~Cell();
  void write_to_cell(const std::string &);
  std::string get_content() const;
  bool is_blank() const;
  std::shared_ptr<Cell> get_next_cell();
  std::shared_ptr<Cell> get_previous_cell();
};

#endif