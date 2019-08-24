/**
 * Created by Erick Velez on 8/23/19.
 *
 *
 */

#ifndef CONFIGURATIONS_H
#define CONFIGUATIONS_H

#include <experimental/filesystem>
#include <string>

//NOTE: will need to refactor once C++17-compliant compiler is used
//TODO: get C++17 compliant compiler
//NOTE: Xcode beta seems to be only reliable solution while on macos15 beta
namespace fs = std::experimental::filesystem;

namespace configuration {
    namespace {
        void openFile(fs::path filePath);
    }
}

#endif
