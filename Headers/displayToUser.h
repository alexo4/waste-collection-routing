//
// Created by Alexander O'Carroll on 02/05/2024.
//

#ifndef GARBAGEAUTOMATICMANAGEMENTSYSTEM_DISPLAYTOUSER_H
#define GARBAGEAUTOMATICMANAGEMENTSYSTEM_DISPLAYTOUSER_H

#include <iostream>
#include <vector>

class displayToUser {

public:
    displayToUser();
    void displayInformation();

private:
    double getFuelCost(double);
    double getTimeTaken(double, int);
    double getWages(double, double);
    double getTotalCost(double, int, double);
    void displayPickUpRoute(std::vector<int>, std::vector<int>);

};


#endif //GARBAGEAUTOMATICMANAGEMENTSYSTEM_DISPLAYTOUSER_H
