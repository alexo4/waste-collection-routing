//
// Created by Alexander O'Carroll on 24/04/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_GREEDYROUTE_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_GREEDYROUTE_H

#include <iostream>
#include <vector>
#include "GarbageLocations.h"

class GreedyRoute {

public:
    GreedyRoute(GarbageLocations*);
    std::vector<int> getGreedyRoute();
    std::vector<int> getFullRoute();
    int getDistance();

private:
    void findGreedyRoute();
    std::vector<int> dijkstrasAlgorithm(std::vector<std::vector<std::array<int, 2>>>, int, int, std::vector<int>);
    int nextInDijkstra(std::vector<int>, std::vector<int>);
    int getClosestGarbage(std::vector<int>, std::vector<int>);
    GarbageLocations* gl;
    vector<int> greedyRoute;
    vector<int> fullRoute;
    int distance;

};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_GREEDYROUTE_H
