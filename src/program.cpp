/** \file program.cpp */

#include <iostream>
#include <array>
#include <exception>
#include <iostream>
#include <string>
#include "program.h"

std::array<std::string, 9> program_keys = {"name", "blank_symbol", "initial_state", "function_table", "tape_alphabet", "input_alphabet", "halting_states", "states", "arguments"};

Program::Program()
{
  this->verified = false;
}

Program::~Program() {}

bool Program::verify(const json& program_to_verify)
{
  for (auto& key : program_keys)
  {
    if (program_to_verify.find(key) == program_to_verify.end())
    {
      throw std::runtime_error("Necessary program key not found.\nChosen file is not a valid program.");
    }
  }
  return true;
}

bool Program::load(const json& program_json)
{
  try
  {
    this->verify(program_json);
  } catch (const std::runtime_error& e)
  {
    throw e;
  }
  this->name = program_json["name"];
  this->blank_symbol = program_json["blank_symbol"];
  this->initial_state = program_json["initial_state"];

  json function_table = program_json["function_table"];
  json tape_alphabet = program_json["tape_alphabet"];
  json input_alphabet = program_json["input_alphabet"];
  json halting_states = program_json["halting_states"];
  json states = program_json["states"];
  json arguments = program_json["arguments"];

  this->function_table = std::vector<std::map<std::string, std::string>>();
  for (json::iterator table_it = function_table.begin(); table_it != function_table.end(); ++table_it)
  {
    auto new_transition = std::map<std::string, std::string>();
    for (json::iterator transition_it = (*table_it).begin(); transition_it != (*table_it).end(); ++transition_it)
    {
      new_transition[transition_it.key()] = transition_it.value();
      std::cout << transition_it.key() << std::endl;
    }
    this->function_table.push_back(new_transition);
  }

  this->tape_alphabet = string_vector();
  for (auto &tape_it : tape_alphabet)
  {
    this->tape_alphabet.push_back(tape_it);
  }

  this->input_alphabet = string_vector();
  for (auto &input_it : input_alphabet)
  {
    this->input_alphabet.push_back(input_it);
  }

  this->alphabet = string_vector();
  std::set_union(this->input_alphabet.begin(), this->input_alphabet.end(), this->tape_alphabet.begin(), this->tape_alphabet.end(), std::back_inserter(this->alphabet));

  this->halting_states = string_vector();
  for (auto &halting_it : halting_states)
  {
    this->halting_states.push_back(halting_it);
  }

  this->states = string_vector();
  for (auto &states_it : states)
  {
    this->states.push_back(states_it);
  }

  this->arguments = string_vector();
  for (auto &arguments_it : arguments)
  {
    this->arguments.push_back(arguments_it);
  }
  return true;
}

std::vector<std::string> Program::get_arguments()
{
  return this->arguments;
}

string_vector Program::get_halting_states()
{
  return this->halting_states;
}

string Program::get_initial_state()
{
  return this->initial_state;
}

std::string Program::get_blank_symbol()
{
  return this->blank_symbol;
}

std::vector<std::map<std::string, std::string>> Program::get_function_table()
{
  return this->function_table;
}