//
// Created by Alexander O'Carroll on 19/04/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_OPTIMISEDROUTE_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_OPTIMISEDROUTE_H

#include <vector>
#include "GarbageLocations.h"
#include "FloydWarshall.h"

class optimisedRoute {

public:
    optimisedRoute(GarbageLocations *gl);
    vector<int> getBestRoute();
    vector<int> getFullRoute();
    int getDistance() const;

private:
    GarbageLocations *gl;
    void findOptimisedRoute();
    int getNClosest(int, int, vector<vector<int>>, vector<int>);
    vector<int> shortestPath(int, vector<int>, vector<int>, int, int, int, vector<int>, vector<vector<int>>);
    int getRouteDistance(vector<int>, vector<vector<int>>);
    vector<int> bestRoute;
    vector<int> fullRoute;
    vector<int> bestToFullRoute(FloydWarshall *);
    int distance;


};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_OPTIMISEDROUTE_H
