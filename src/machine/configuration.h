#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <set>
#include <string>
#include <turing_machine.h>

/**
 * A Configuration instance represents the "settings" of the Turing_Machine program.
 *
 * It holds references to existing config files and is called to initialize the fields of a TM.
 */
class Configuration {
private:
public:
    /**
     * Default constructor will initialize directory_entries vector from constant programs dir
     */
    Configuration();

    /**
     * Destructor will destroy directory_entries vector
     */
    ~Configuration();


};

#endif
