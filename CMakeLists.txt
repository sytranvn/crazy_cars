cmake_minimum_required(VERSION 3.0)
project(crazy_cars)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/NCursesConsole.h"
    "${PROJECT_SOURCE_DIR}/src/NCursesConsole.cpp"
)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(crazy_cars ${all_SRCS})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
target_include_directories(crazy_cars PUBLIC "${PROJECT_SOURCE_DIR}/src")
