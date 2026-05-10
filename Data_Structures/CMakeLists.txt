cmake_minimum_required(VERSION 3.18)
project(DataStructures)

# C++ standartlarını ayarla
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Alt klasörleri (veri yapılarını) projeye dahil et
add_subdirectory(Array)
add_subdirectory(Linked_List)