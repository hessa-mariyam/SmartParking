#include "vehicle.h"
#include <algorithm>
using namespace std;

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
