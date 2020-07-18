/** \file program.h */

#ifndef PROGRAM_H
#define PROGRAM_H
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

typedef std::tuple<std::string, std::string, std::string, std::string> function_table_entry; 
typedef std::string string;
typedef std::vector<string> string_vector;

class Program {
private:
    string_vector alphabet; ///< The super set containing the tape and input alphabets
    string_vector tape_alphabet; ///< The alphabet that is written on the tape 
    string_vector input_alphabet; ///< The alphabet that makes up the TM input
    string_vector states; ///< the possible states of the program
    string_vector halting_states; ///< the states thate the program will halt on
    string_vector arguments; ///< The initial input to be given to the TM
    std::vector<std::map<std::string, std::string>> function_table; ///< all transitions
    string blank_symbol; ///< the symbol representing a blank Cell
    string initial_state; 
    string name;
public:
    /**
     * \brief Weak construction
     */
    Program();

    /**
     * \brief Construct using a JSON object
     * 
     * \details The JSON object will be verified to have all of the components needed to be used for a TM
     * 
     * \param program_json
     */
    explicit Program(json const&);
    bool verify() noexcept(false);
    string_vector get_arguments();
};
#endif