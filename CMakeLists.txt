cmake_minimum_required(VERSION 3.6)
project(cheat_code_compilation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        src/implementation/internal/definitions.hpp
        src/implementation/internal/enumerations.hpp
        src/implementation/internal/internal_templates.hpp
        src/implementation/internal/library_functions.hpp
        src/implementation/internal/pointer_utilties.hpp
        src/implementation/templates.hpp
        src/implementation/examples/mario_kart_8.hpp)
add_executable(cheat_code_compilation ${SOURCE_FILES})