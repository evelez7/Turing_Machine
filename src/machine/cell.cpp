#include "cell.h"

Cell::Cell(const std::string &to_write)
{
  this->content = to_write;
  this->blank = false;
}

Cell::Cell(const std::string &to_write, bool blank)
{
  this->blank = blank;
  if (!this->blank)
  {
    this->content = to_write;
  }
}

Cell::Cell()
{
  this->blank = true;
}

Cell::~Cell() {}

void Cell::write_to_cell(const std::string &to_write)
{
  this->content = to_write;
}

std::string Cell::get_content() const
{
  return this->content;
}

bool Cell::is_blank() const
{
  return this->blank;
}

std::shared_ptr<Cell> Cell::get_next_cell()
{
  return this->next;
}

std::shared_ptr<Cell> Cell::get_previous_cell()
{
  return this->previous;
}