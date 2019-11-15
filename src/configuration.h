#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <experimental/filesystem>
#include <string>
#include <set>
#include <turing_machine.h>
#include <nlohmann/json.hpp>

namespace fs = std::experimental::filesystem;

using json = nlohmann::json;

namespace config {
/**
 * A Configuration instance represents the "settings" of the Turing_Machine program, not
 * the TM itself.
 *
 * It holds references to existing config files and is called to initialize the fields of a TM.
 */
class Configuration {
private:
    /**
     * A vector of directory_entry objects representing files in the configs directory
     */
    std::vector<fs::directory_entry>* directory_entries;

    /**
     * Checks if the a given path string exists as a directory_entry in configs directory
     *
     * May throw an exception
     *
     * @param file_path object representing path to directory_entry
     * @return bool, true if file is valid
     */
    bool path_exists(const fs::path& file_path);

    /**
     * Opens a given ifstream using given file_path
     *
     * It's assumed that the ifstream was declared in the calling function so nothing is returned
     * but this method throws an exception if the file is not opened (exception or ifstream::failure
     *
     * @param config_file std::ifstream
     * @param file_path filesystem::path
     */
    void open_file(std::ifstream& config_file, const fs::path& file_path);

    /**
     * Checks whether an existing, open file conforms to the structure of a config file
     *
     * @param config_file
     * @return bool true if json file is of valid structure
     */
    bool is_valid_config(json config_file)
public:
    /**
     * Default constructor will initialize directory_entries vector from constant configs dir
     */
    Configuration();

    /**
     * Destructor will destroy directory_entries vector
     */
    ~Configuration();

    /**
     * Returns the number of file entries in the configs directory
     *
     * @return int
     */
    int get_directory_size();

    /**
     * This method will call the other configure_machine method after converting string file_path
     * to a path object
     *
     * @param machine Turing_Machine to configure with states, transitions, etc
     * @param file_path string
     */
    void configure_machine(Turing_Machine& machine, const std::string& file_path);

    /**
     * Will open the directory_entry in directory_entries vector corresponding to file_path
     * and convert it to JSON so that machine can be configured
     *
     * Existence of file_path will be guaranteed, but this method itself will not throw an exception
     *
     * @param machine Turing_Machine to configure with states, transitions, etc
     * @param file_path filesystem::path
     */
    void configure_machine(Turing_Machine& machine, const fs::path& file_path);
};
}

#endif
