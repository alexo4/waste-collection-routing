//
// Created by Alexander O'Carroll on 12/04/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_FLOYDWARSHALL_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_FLOYDWARSHALL_H

#include <iostream>
#include <vector>
#include <array>

class FloydWarshall {

public:
    FloydWarshall(std::vector<std::vector<std::array<int, 2>>> adjLists);
    std::vector<std::vector<int>> getShortestPathMatrix();
    std::vector<int> getPath(int u, int v);

private:
    std::vector<std::vector<std::array<int, 2>>> adjLists;
    std::vector<std::vector<int>> shortestPathMatrix;
    std::vector<std::vector<int>> nextNodeMatrix;
    void findShortestPath();
    void initialiseSPMatrix();

};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_FLOYDWARSHALL_H
