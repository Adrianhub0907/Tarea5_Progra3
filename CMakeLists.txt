cmake_minimum_required(VERSION 3.20)
project(Tarea5_Progra3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Tarea5_Progra3 main.cpp ${SOURCES}
        include/ejercicio2/RenderFactory.h
        src/ejercicio2/RenderFactory.cpp
        src/ejercicio2/Elementos.cpp
        include/ejercicio2/Elementos.h)

find_package(Threads REQUIRED)
target_link_libraries(Tarea5_Progra3 PRIVATE Threads::Threads)