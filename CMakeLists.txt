cmake_minimum_required(VERSION 3.16)
project(OptimizedStorage)

# Ensure the build folder is always recreated
execute_process(COMMAND rm -rf ${CMAKE_BINARY_DIR}
                COMMAND mkdir -p ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(storage storage.cpp)

target_link_libraries(storage PRIVATE c++ pthread)
