cmake_minimum_required(VERSION 3.14...3.22)

project(Chapter0)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

# ---- Executable ----

add_executable(Chapter0 main.cpp)
target_compile_features(Chapter0 PRIVATE cxx_std_17)
target_link_libraries(Chapter0)
