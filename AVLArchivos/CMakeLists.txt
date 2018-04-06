cmake_minimum_required(VERSION 3.8)
project(AVLArchivos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp nodo.cpp nodo.h datafile.cpp datafile.h avlarbol.cpp avlarbol.h)
add_executable(AVLArchivos ${SOURCE_FILES})