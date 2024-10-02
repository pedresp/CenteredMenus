cmake_minimum_required(VERSION 3.13)
project(TEST VERSION 1.0)

cmake_policy(SET CMP0077 NEW)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_BUILD_TYPE Release)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#set(USE_GCC_VERSION OFF)
#set(USE_CMS_WCHAR ON)

add_subdirectory(cms)
add_executable(main main.c)

target_link_libraries(main PUBLIC cms)