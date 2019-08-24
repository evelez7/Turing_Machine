/**
 * Turing Machine
 * 
 * Author: Erick Velez
 */

#include <iostream>

namespace filesystem = std::filesystem;

void printIntro() {

    for (int i = 0; i < 50; ++i) {
        printf("=");
    }
    std::cout << std::endl;

    printf("Turing Machine Emulator");
}

void openConfigDirectory() {

}

int main() {
    printIntro();
    return 0;
}
