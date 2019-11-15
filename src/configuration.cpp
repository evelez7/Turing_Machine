//
// Created by Erick Velez on 8/23/19.
//

#include "configuration.h"
#include "../libraries/nlohmann/json.hpp"
#include <list>
#include <iostream>
#include <fstream>
#include <vector>

#define CONFIG_DIR_PATH "../configs"

using json = nlohmann::json;

bool config::Configuration::path_exists(const fs::path &file_path){

}

void config::Configuration::open_file(std::ifstream &config_file, const fs::path &file_path){
    try {
        config_file.open(file_path.string());
        if (!config_file.is_open()) {
            throw std::exception();
        }
    } catch (const std::ifstream::failure& exception) {
        std::cout << "Exception while opening config file" << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Configuration file could not be opened" << std::endl;
    }
}

// Configuration constructor takes no argument since the config file dir path is already predefined
// The dir path should remain constant
config::Configuration::Configuration() {
    this->directory_entries = new std::vector<fs::directory_entry>();
    for (const auto& entry : fs::directory_iterator(CONFIG_DIR_PATH)) {
        directory_entries->push_back(entry);
    }
}

int config::Configuration::get_directory_size() {
    return this->directory_entries->size();
}

void config::Configuration::configure_machine(Turing_Machine& machine, const std::string& file_path) {
    fs::path converted_file_path = fs::path(file_path);

    configure_machine(machine, converted_file_path);
}


void config::Configuration::configure_machine(Turing_Machine& machine, const fs::path& file_path) {
    std::ifstream config_file;
    auto* config_master = new Configuration();

    json config_json = json::parse(config_file);

//    std::vector<std::string>* machine_states =
}
