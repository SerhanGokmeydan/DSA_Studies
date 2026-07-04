cmake_minimum_required(VERSION 3.18)
project(DataStructures)

# C++ standartlarını ayarla
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ALL_ITEMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*")

add_subdirectory(Array)
add_subdirectory(Linked_List)
add_subdirectory(Stack)
