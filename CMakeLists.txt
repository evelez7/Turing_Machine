cmake_minimum_required(VERSION 3.16)
project(turing_machine CXX)

# Included in this file are CMake commands which are supposed to allow for integration without flags
# When used, the JSON lib files are not linked and raise errors when including each other. (cannot find nlohmann/serializer.cpp)
# Which sucks, because I do not like having to specify version numbers,
#if these are used, then use <json.hpp>
# set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake_Modules/)

# Change version number here to build, assuming same homebrew config
# if this is used, use <nlohmann/json.hpp>
set(CMAKE_CXX_FLAGS "-I/usr/local/Cellar/nlohmann-json/3.9.1_1/include/")

# find_package(nlohmann-json REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(SRC ./src)
include_directories(${SRC})

set(
        SOURCE
            ${SRC}/main.cpp
            ${SRC}/program.cpp
            ${SRC}/util.cpp
            ${SRC}/machine/cell.cpp
            ${SRC}/machine/configuration.cpp
            ${SRC}/machine/tape.cpp
            ${SRC}/machine/turing_machine.cpp
)

set(
    HEADERS
            ${SRC}/util.h
            ${SRC}/machine/cell.h
            ${SRC}/machine/configuration.h
            ${SRC}/machine/turing_machine.h
            ${SRC}/machine/tape.h
            ${SRC}/program.h
)

add_executable(turing_machine.exe ${SOURCE})
# target_include_directories(turing_machine.exe PRIVATE ${JSON_INCLUDE_DIR})