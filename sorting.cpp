#include "vehicle.h"
#include <algorithm>
using namespace std;

void sortByArrival(vector<Vehicle>& v)
{
    sort(v.begin(), v.end(),
        [](Vehicle a, Vehicle b)
        {
            return a.arrival < b.arrival;
        });

    cout << "\nSorted by Arrival Time:\n";
    displayVehicles(v);
}

void sortByDuration(vector<Vehicle>& v)
{
    sort(v.begin(), v.end(),
        [](Vehicle a, Vehicle b)
        {
            return a.duration < b.duration;
        });

    cout << "\nSorted by Parking Duration:\n";
    displayVehicles(v);
}
