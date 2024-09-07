cmake_minimum_required(VERSION 3.26)
project(Rad)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rad main.cpp
        AddressFunction.cpp
        AddressFunction.h
        LinearAddressing.cpp
        LinearAddressing.h
        HashTable.cpp
        HashTable.h
        Meni.cpp
        Meni.h
        AdaptiveHashTable.cpp
        AdaptiveHashTable.h
        QuadraticHashing.cpp
        QuadraticHashing.h
        FileIO.h
        FileIO.cpp
)
