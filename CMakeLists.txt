cmake_minimum_required(VERSION 3.27)
project(GarbageAutomaticManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(GarbageAutomaticManagementSystem src/main.cpp
        src/GarbageLocations.cpp
        Headers/GarbageLocations.h
        src/FloydWarshall.cpp
        Headers/FloydWarshall.h
        src/optimisedRoute.cpp
        Headers/optimisedRoute.h
        src/GreedyRoute.cpp
        Headers/GreedyRoute.h
        src/displayToUser.cpp
        Headers/displayToUser.h
        src/nonOptimisedRoute.cpp
        Headers/nonOptimisedRoute.h
        src/saveToFile.cpp
        Headers/saveToFile.h)
