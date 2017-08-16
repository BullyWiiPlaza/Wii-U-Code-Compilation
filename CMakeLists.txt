cmake_minimum_required(VERSION 3.6)
project(cheat_code_compilation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        src/definitions.h
        src/enumerations.h
        src/internal_templates.h
        src/library_functions.h
        src/pointer_utilties.h
        src/templates.h)
add_executable(cheat_code_compilation ${SOURCE_FILES})