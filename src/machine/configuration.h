#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include "tape.h"
#include "cell.h"
#include <string>
#include <memory>
#include <vector>

/**
 * A Configuration instance represents the "settings" of the Turing_Machine program.
 *
 * It holds references to existing config files and is called to initialize the fields of a TM.
 */
class Configuration {
private:
    std::string state;
    std::shared_ptr<Cell> cell;
    std::vector<std::shared_ptr<Cell>> active_tape_left;
    std::vector<std::shared_ptr<Cell>> active_tape_right;
public:
    /**
     * Default constructor will initialize directory_entries vector from constant programs dir
     */
    Configuration(const Tape &, std::string );
    Configuration();
    std::string get_state();
};

#endif
