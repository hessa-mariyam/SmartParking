#include "vehicle.h"
#include <unordered_map>
using namespace std;

unordered_map<string, Vehicle> vehicleHash;

void addVehicle(vector<Vehicle>& v)
{
    Vehicle x;

    cout << "Enter Registration Number: ";
    cin >> x.regNo;

    if (vehicleHash.find(x.regNo) != vehicleHash.end())
    {
        cout << "Vehicle already exists!\n";
        return;
    }

    cout << "Enter Arrival Time (0-23): ";
    cin >> x.arrival;

    cout << "Enter Parking Duration (hours): ";
    cin >> x.duration;

    cout << "Enter Parking Fee (Rs): ";
    cin >> x.fee;

    if (x.arrival < 0 || x.arrival > 23 ||
        x.duration <= 0 || x.fee < 0)
    {
        cout << "Invalid input!\n";
        return;
    }

    v.push_back(x);
    vehicleHash[x.regNo] = x;

    cout << "Vehicle Added Successfully!\n";
}

void searchVehicle(vector<Vehicle>& v)
{
    string reg;

    cout << "Enter Registration Number to Search: ";
    cin >> reg;

    auto it = vehicleHash.find(reg);

    if (it == vehicleHash.end())
    {
        cout << "Vehicle Not Found!\n";
        return;
    }

    Vehicle x = it->second;

    cout << "\nVehicle Details\n";
    cout << "Registration: " << x.regNo << endl;
    cout << "Arrival Time: " << x.arrival << endl;
    cout << "Duration: " << x.duration << " hours\n";
    cout << "Parking Fee: Rs " << x.fee << endl;
}

void displayVehicles(vector<Vehicle>& v)
{
    if (v.empty())
    {
        cout << "No vehicles available!\n";
        return;
    }

    cout << "\nRegistration\tArrival\tDuration\tFee\n";

    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i].regNo << "\t\t"
             << v[i].arrival << "\t"
             << v[i].duration << "\t\t"
             << v[i].fee << endl;
    }
}
