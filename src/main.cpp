/** @file main.cpp */
#include "./machine/turing_machine.h"
#include "program.h"
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <iomanip>

using nlohmann::json;
namespace fs = std::filesystem;

// BEGIN forward declarations
/**
 * @brief Print intro, version number
 */
void print_intro();

/**
 * @brief Attempts to open the ./programs directory, without creating it
 *
 * @return std::vector<fs::path> a collection of paths to potential Programs in JSON
 */
std::vector<fs::path> open_program_dir();

void print_programs(const std::vector<fs::path> &);
int get_user_input(int const &);
// END forward declarations

int main()
{
  print_intro();
  std::vector<fs::path> program_paths;
  // attempt to open an existing programs
  try
  {
    program_paths = open_program_dir();
  }
  catch (fs::filesystem_error const &error)
  {
    std::cout << error.what() << std::endl;
    return -1;
  }

  int choice;
  Program program_to_execute;
  do
  {
    std::cout << "\nThe following programs are available: " << std::endl;
    print_programs(program_paths);
    choice = get_user_input(program_paths.size());
    if (choice == -1)
      continue;

    auto program_to_execute_path = program_paths.at(choice);
    std::ifstream program_to_execute_file(program_to_execute_path.c_str(),
                                          std::ios::binary);

    json program_to_execute_json;
    // feed raw stream to json object
    program_to_execute_file >> program_to_execute_json;
    try
    {
      program_to_execute.load(program_to_execute_json);
    } catch (const std::runtime_error& e)
    {
      std::cout << e.what() << std::endl;
      continue;
    }
    break;
  } while (true);

  auto program_ptr = std::make_shared<Program>(program_to_execute);
  Turing_Machine tm(program_ptr);
  tm.print_tape();
  tm.execute();
  return 0;
}

int get_user_input(int const &size)
{
  int option;
  std::cout << "Choose a program to execute: " << std::flush;
  std::cin >> option;
  if (std::cin.fail() || option > size || option <= 0)
  {
    std::cin.clear();
    printf("Incorrect input, please select from the available options.\n");
    return -1;
  }
  option += -1;
  return option;
}

void print_bars()
{
  for (int i = 0; i < 50; ++i)
  {
    printf("=");
  }
  std::cout << std::endl;
}

void print_intro()
{
  print_bars();
  printf("Turing Machine Emulator v0.1 by Erick Velez\n");
  print_bars();
}

void print_programs(const std::vector<fs::path> &program_paths)
{
  int count = 1;
  for (auto &path : program_paths)
  {
    std::cout << std::left << count << std::setw(3) << ".)" << std::setw(20) << path.filename() << std::endl;
    count += 1;
  }
}

std::vector<fs::path> open_program_dir()
{
  fs::path current_path = fs::current_path();
  // ./programs or ./turing_machine/programs
  fs::path programs_dir_path = current_path / "programs";

  if (!fs::is_directory(programs_dir_path))
    throw fs::filesystem_error("Programs path does not exist",
                               programs_dir_path, std::error_code());

  std::vector<fs::path> program_paths;
  for (auto &entry : fs::directory_iterator(programs_dir_path))
    program_paths.push_back(entry.path());
  return program_paths;
}
