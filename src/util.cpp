#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void open_file(std::ifstream &config_file, const fs::path &file_path){
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