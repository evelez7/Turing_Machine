cmake_minimum_required(VERSION 3.16)
project(turing_machine)

set(CMAKE_CXX_STANDARD 17)
set(TEST ./test)
set(SRC ./src)

option(TURING_MACHINE_USE_EXTERNAL_JSON "Use an external JSON library" OFF)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/dependencies/)


include_directories(${TEST})
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

add_executable(turing_machine ${SOURCE})
target_link_libraries(turing_machine nlohmann_json::nlohmann_json)
target_link_libraries(turing_machine nlohmann_json)
