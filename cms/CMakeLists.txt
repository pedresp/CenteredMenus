cmake_minimum_required(VERSION 3.13)
project(CMS VERSION 2.0)


option(USE_GCC_VERSION "Build C library version (using GCC)" ON)
option(USE_CMS_WCHAR "Links with menuw and ncursesw to handle locales" OFF)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

if(USE_GCC_VERSION)
    set(CMAKE_C_STANDARD 11)
    add_library(cms CenteredMenu.c)
else()
    set(CMAKE_CXX_STANDARD 11)
    add_library(cms CenteredMenu.cpp)
endif()

if(USE_CMS_WCHAR)
    target_link_libraries(cms PUBLIC menuw ncursesw)
else()
    target_link_libraries(cms PUBLIC menu ${CURSES_LIBRARIES})
endif()

target_include_directories(cms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})