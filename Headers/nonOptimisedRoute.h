//
// Created by Alexander O'Carroll on 02/05/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_NONOPTIMISEDROUTE_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_NONOPTIMISEDROUTE_H

#include "GarbageLocations.h"
#include <vector>

class nonOptimisedRoute {

public:
    nonOptimisedRoute(GarbageLocations *gl);
    vector<int> getPickUpPoints();
    vector<int> getFullRoute();
    int getDistance();

private:

    GarbageLocations *gl;
    vector<int> pickUpPoints;
    vector<int> fullRoute;
    void findRoute();

};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_NONOPTIMISEDROUTE_H
