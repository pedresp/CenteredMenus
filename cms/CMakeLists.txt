cmake_minimum_required(VERSION 3.10)
project(CMS VERSION 2.0)


option(USE_GCC_VERSION "Build C library version (using GCC)" ON)
find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

if(USE_GCC_VERSION)
    set(CMAKE_C_STANDARD 11)
    add_library(cms CenteredMenu.c)
else()
    set(CMAKE_CXX_STANDARD 11)
    add_library(cms CenteredMenu.cpp)
endif()

target_include_directories(cms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cms PUBLIC menu ncursesw)