/**
 * Created by Erick Velez on 8/23/19.
 *
 *
 */

#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <experimental/filesystem>
#include <string>
#include <set>
#include "turing_machine.h"

//NOTE: will need to refactor once C++17-compliant compiler is used
//TODO: get C++17 compliant compiler, dont like experimental
//NOTE: Xcode beta seems to be only reliable solution while on macos15 beta
namespace fs = std::experimental::filesystem;

namespace config {
class Configuration {
private:
    std::vector<fs::directory_entry>* directory_entries;
    bool path_exists(const fs::path& file_path);
    void open_file(std::ifstream& config_file, const fs::path& file_path);
public:
    Configuration();
    int get_directory_size();

    // See definition of overloaded cousin below
    // This function merely converts the string file_path to a path object
    // then redirects to below/
    void configure_machine(Turing_Machine& machine, const std::string& file_path);

    // Called within the constructor of a turing_machine, this is a friend function
    // of turing_machine
    //
    // Note that it is preferred to keep a filesystem::path object in case we would like to
    // do some operations regarding the config subdirectory
    //
    // @params machine the calling turing_machine
    // @params file_path an object of type fs::path representing the config file
    void configure_machine(Turing_Machine& machine, const fs::path& file_path);
};
}

#endif
