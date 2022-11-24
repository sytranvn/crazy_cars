cmake_minimum_required(VERSION 3.0)
project(crazy_cars)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/NCursesConsole.h"
    "${PROJECT_SOURCE_DIR}/src/NCursesConsole.cpp"
    "${PROJECT_SOURCE_DIR}/src/Car.h"
    "${PROJECT_SOURCE_DIR}/src/Car.cpp"
    "${PROJECT_SOURCE_DIR}/src/F1.h"
    "${PROJECT_SOURCE_DIR}/src/F1.cpp"
)

add_executable(crazy_cars ${all_SRCS})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
target_include_directories(crazy_cars PUBLIC "${PROJECT_SOURCE_DIR}/src")
