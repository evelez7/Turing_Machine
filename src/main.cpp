#include <exception>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>
#include "./machine/turing_machine.h"
#include "program.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

void print_bars();
std::vector<fs::path> open_program_dir() noexcept(false);
int get_user_input(int const&);

int main() {
    print_bars();
    printf("Turing Machine Emulator v0.1 by Erick Velez\n");
    print_bars();
    printf("The following programs are available: \n");

    std::vector<fs::path> program_paths;
    try {
        program_paths = open_program_dir();
    } catch (fs::filesystem_error const& error) {
        std::cout << error.what() << std::endl;
        return -1;
    }
    printf("\nChoose a program to run: ");
    int choice = get_user_input(program_paths.size());
    auto program_to_execute_path = program_paths.at(choice);
    std::ifstream program_to_execute_file(program_to_execute_path.c_str(), std::ios::binary);

    json program_to_execute_json;
    program_to_execute_file >> program_to_execute_json;
    Program program_to_execute(program_to_execute_json);
    auto program_ptr = std::make_shared<Program>(program_to_execute);
    Turing_Machine tm(program_ptr);
    return 0;
}

int get_user_input(int const& size) {
    int option;
    while (true) {
        std::cin >> option;
        if (std::cin.fail() || option >= size || option <= 0) {
            std::cin.clear();
            printf("Incorrect input, please select from the available options");
            continue;
        }
        break;
    }
    option += -1;
    return option;
}

void print_bars() {
    for (int i = 0; i < 50; ++i) {
        printf("=");
    }
    std::cout << std::endl;
}

std::vector<fs::path> open_program_dir() noexcept(false) {
    fs::path current_path = fs::current_path();
    fs::path programs_dir_path = current_path / "programs";

    if (!fs::is_directory(programs_dir_path)) {
        throw fs::filesystem_error("Programs path does not exist", programs_dir_path, std::error_code());
    }

    int count = 1;
    std::vector<fs::path> program_paths;
    for (auto &entry : fs::directory_iterator(programs_dir_path)) {
        std::cout << count << ".) "  << entry.path().filename() << std::endl;
        program_paths.push_back(entry.path());
        ++count;
    }
    return program_paths;
}
