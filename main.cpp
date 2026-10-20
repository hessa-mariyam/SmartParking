#include "vehicle.h"
using namespace std;

int main()
{
    vector<Vehicle> vehicles;
    int choice;

    do
    {
        cout << "\n===== SMART PARKING SYSTEM =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Search Vehicle (Hashing)\n";
        cout << "3. Display Vehicles\n";
        cout << "4. Sort by Arrival Time\n";
        cout << "5. Sort by Parking Duration\n";
        cout << "6. Allocate Parking (DP)\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addVehicle(vehicles);
                break;

            case 2:
                searchVehicle(vehicles);
                break;

            case 3:
                displayVehicles(vehicles);
                break;

            case 4:
                sortByArrival(vehicles);
                break;

            case 5:
                sortByDuration(vehicles);
                break;

            case 6:
                allocateParking(vehicles);
                break;

            case 7:
                cout << "Exiting Smart Parking System...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
