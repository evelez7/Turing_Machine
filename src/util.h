#ifndef UTIL_H
#define UTIL_H

#include <filesystem>

namespace fs = std::filesystem;

/**
     * A vector of directory_entry objects representing files in the programs directory
     */
std::vector<fs::directory_entry> *directory_entries;

/**
     * Checks if the a given path string exists as a directory_entry in programs directory
     *
     * May throw an exception
     *
     * @param file_path object representing path to directory_entry
     * @return bool, true if file is valid
     */
bool path_exists(const fs::path &file_path);

/**
     * Opens a given ifstream using given file_path
     *
     * It's assumed that the ifstream was declared in the calling function so nothing is returned
     * but this method throws an exception if the file is not opened (exception or ifstream::failure
     *
     * \param config_file std::ifstream
     * \param file_path filesystem::path
     */
void open_file(std::ifstream &config_file, const fs::path &file_path);

/**
     * Checks whether an existing, open file conforms to the structure of a config file
     *
     * \param config_file
     * \return bool true if json file is of valid structure
     */
bool is_valid_config(json config_file);

/**
     * Returns the number of file entries in the programs directory
     *
     * \return int
     */
int get_directory_size();

#endif