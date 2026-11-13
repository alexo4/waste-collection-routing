//
// Created by Alexander O'Carroll on 08/04/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_GARBAGELOCATIONS_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_GARBAGELOCATIONS_H


#include <vector>
#include <array>
using namespace std;

class GarbageLocations {

public:
    GarbageLocations();
    void loadGarbageLocations();
    void generateWasteLevels();
    std::vector<int> getLocationsByWaste(int);
    std::vector<std::vector<std::array<int, 2>>> getAdjLists();
    void printGarbageLocations();
    void printWasteLevels();
    std::vector<int> getWasteLevels();


private:

    std::vector<std::vector<std::array<int, 2>>> adjLists;
    std::vector<int> wasteLevels;
    int numOfLocations{};
    void findNumOfLocations();

};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_GARBAGELOCATIONS_H
