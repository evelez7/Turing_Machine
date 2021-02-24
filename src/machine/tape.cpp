#include "tape.h"
#include "cell.h"
#include <iostream>

Tape::Tape(const std::vector<std::string> &to_write)
{
  this->cell_list = std::list<std::shared_ptr<Cell>>();
  for (const auto &symbol : to_write)
  {
    auto new_cell = std::make_shared<Cell>(symbol);
    this->cell_list.emplace_back(new_cell);
  }
  this->size = this->cell_list.size();
}

void Tape::print() const
{
  for (int i = 0; i < this->cell_list.size(); ++i)
  {
    printf("=====");
  }
  printf("\n");
  for (auto const &current_cell : this->cell_list)
  {
    printf("| ");
    std::cout << current_cell->get_content();
    printf(" |");
  }
  printf("\n");
  for (int j = 0; j < this->cell_list.size(); ++j)
  {
    printf("=====");
  }
}

int Tape::get_size() const
{
  return this->size;
}

std::shared_ptr<Cell> Tape::get_first() const
{
  return *(this->cell_list.begin());
}

void Tape::write(const std::string &to_write)
{
  this->cell_list.emplace_back(new Cell(to_write));
}

void Tape::write(const std::string &to_write, bool blank)
{
  this->cell_list.emplace_back(new Cell(to_write, blank));
}