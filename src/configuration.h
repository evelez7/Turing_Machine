/**
 * Created by Erick Velez on 8/23/19.
 *
 *
 */

#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <experimental/filesystem>
#include <string>
#include "turing_machine.h"

//NOTE: will need to refactor once C++17-compliant compiler is used
//TODO: get C++17 compliant compiler, dont like experimental
//NOTE: Xcode beta seems to be only reliable solution while on macos15 beta
namespace fs = std::experimental::filesystem;

namespace config {
    void configure_machine(Turing_Machine machine, std::string file_path);
    void configure_machine(Turing_Machine machine, fs::path file_path);
}

#endif
