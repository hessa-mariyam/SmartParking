#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Vehicle
{
    string regNo;
    int arrival;
    int duration;
    int fee;
};

unordered_map<string, Vehicle> vehicleHash;

int calculateFee(int duration)
{
    return duration * 100;
}

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

    if (x.arrival < 0 || x.arrival > 23 ||
        x.duration <= 0)
    {
        cout << "Invalid input!\n";
        return;
    }

  
    x.fee = calculateFee(x.duration);

    v.push_back(x);
    vehicleHash[x.regNo] = x;

    cout << "Vehicle Added Successfully!\n";
    cout << "Parking Fee: Rs " << x.fee << endl;
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


void allocateParking(vector<Vehicle>& v)
{
    if (v.empty())
    {
        cout << "No vehicles available!\n";
        return;
    }

    int capacity;

    cout << "Enter Available Parking-Space-Hours: ";
    cin >> capacity;

    if (capacity < 0 || capacity > 10000)
    {
        cout << "Invalid capacity!\n";
        return;
    }

    int n = v.size();

   
    vector<vector<int>> dp(
        n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            
            dp[i][j] = dp[i - 1][j];

            
            if (v[i - 1].duration <= j)
            {
                dp[i][j] = max(
                    dp[i][j],
                    v[i - 1].fee +
                    dp[i - 1][j - v[i - 1].duration]);
            }
        }
    }

    int j = capacity;
    vector<int> selected;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            selected.push_back(i - 1);
            j -= v[i - 1].duration;
        }
    }

    reverse(selected.begin(), selected.end());

    cout << "\nSelected Vehicles:\n";

    for (int i : selected)
    {
        cout << "Registration: " << v[i].regNo
             << ", Duration: " << v[i].duration
             << " hours, Fee: Rs " << v[i].fee << endl;
    }

    if (selected.empty())
        cout << "No vehicles selected.\n";

    cout << "Maximum Revenue: Rs "
         << dp[n][capacity] << endl;

    cout << "Parking-Space-Hours Used: "
         << capacity - j << endl;
}

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

