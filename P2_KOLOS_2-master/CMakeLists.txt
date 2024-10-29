cmake_minimum_required(VERSION 3.25)
project(KOLOS_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(KOLOS_2 main.cpp StatekPowietrzny.cpp StatekPowietrzny.hpp Samolot.cpp Samolot.hpp Lotnia.cpp Lotnia.hpp Szybowiec.cpp Szybowiec.hpp Motolotnia.cpp Motolotnia.hpp Lotnisko.cpp Lotnisko.hpp)
