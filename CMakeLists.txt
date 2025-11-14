cmake_minimum_required(VERSION 3.15)

project(MonteCarloPricer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(my_option_pricer
    # The two source files for our library:
    europeanOption.cpp
    binding.cpp
)
