cmake_minimum_required(VERSION 3.14)
project(turing_machine)

set(CMAKE_CXX_STANDARD 17)

set(LIBRARIES ./libraries)
set(TEST ./test)
set(SRC ./src)

include_directories(${LIBRARIES})
include_directories(${TEST})
include_directories(${SRC})

set(
        SOURCE_FILES
            ${SRC}/main.cpp
            ${SRC}/cell.cpp
            ${SRC}/cell.h
            ${SRC}/configuration.cpp
            ${SRC}/configuration.h
            ${SRC}/tape.cpp
            ${SRC}/tape.h
            ${SRC}/turing_machine.cpp
            ${SRC}/turing_machine.h
)

set(
        TEST_FILES
            ${TEST}/main.cpp
            ${TEST}/configuration.cpp
)

add_executable(turing_machine ${SOURCE_FILES})
add_executable(test_suite ${TEST_FILES})
