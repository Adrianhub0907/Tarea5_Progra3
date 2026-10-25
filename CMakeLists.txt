cmake_minimum_required(VERSION 3.20)
project(Tarea5_Progra3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Tarea5_Progra3 main.cpp ${SOURCES}
        include/ejercicio2/RenderFactory.h
        include/ejercicio2/Elementos.h
        include/ejercicio4/Graph.h
        include/ejercicio4/Iterators.h)

find_package(Threads REQUIRED)
target_link_libraries(Tarea5_Progra3 PRIVATE Threads::Threads)