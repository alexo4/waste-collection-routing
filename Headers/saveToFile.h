//
// Created by Alexander O'Carroll on 02/05/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_SAVETOFILE_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_SAVETOFILE_H

#include "GarbageLocations.h"
#include <fstream>

class saveToFile {

public:
    saveToFile(GarbageLocations *gl, std::vector<int>, std::vector<int>);

private:
    GarbageLocations *gl;
    void saveAllInfoToFile(std::vector<int>, std::vector<int>);
    void savePickUpRoute(std::vector<int>, std::vector<int>, ofstream &);
    void saveMap(ofstream &);
    void saveWasteLevel(std::vector<int> wasteLevels, ofstream &);
};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_SAVETOFILE_H
