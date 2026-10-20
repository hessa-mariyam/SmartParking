#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Vehicle
{
    string regNo;
    int arrival;
    int duration;
    int fee;
};

void addVehicle(vector<Vehicle>& v);
void searchVehicle(vector<Vehicle>& v);
void displayVehicles(vector<Vehicle>& v);

void sortByArrival(vector<Vehicle>& v);
void sortByDuration(vector<Vehicle>& v);

void allocateParking(vector<Vehicle>& v);

#endif
