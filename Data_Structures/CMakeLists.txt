cmake_minimum_required(VERSION 3.18)
project(DataStructures)

# C++ standartlarını ayarla
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ALL_ITEMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(ITEM IN LISTS ALL_ITEMS)
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR/${ITEM}}" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${ITEM}/CMakeLists.txt")
        add_subdirectory(${ITEM})
    endif()
endforeach()
