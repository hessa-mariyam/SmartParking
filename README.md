# Smart Parking System

A C++ application that manages vehicle records and optimizes parking revenue using data structures and algorithms.

## Features

- Add vehicle details
- Search vehicles by registration number using hashing
- Display all registered vehicles
- Sort vehicles by arrival time
- Sort vehicles by parking duration
- Allocate parking capacity to maximize revenue

## Algorithms Used

- **Hashing:** Uses `unordered_map` for fast vehicle searches.
- **Sorting:** Uses `sort()` to arrange vehicles by arrival time and parking duration.
- **Dynamic Programming:** Uses the 0/1 Knapsack algorithm to maximize revenue within the available parking-space-hours.

## Technologies Used

- C++
- Standard Template Library (STL)
- Git and GitHub

## Project Structure

```text
SmartParking/
├── main.cpp
└── README.md
```

## How to Compile and Run

Compile the program using a C++17 compiler:

```bash
clang++ -std=c++17 main.cpp -o smartparking
```

Run the program:

```bash
./smartparking
```

## Menu Options

1. Add Vehicle
2. Search Vehicle (Hashing)
3. Display Vehicles
4. Sort by Arrival Time
5. Sort by Parking Duration
6. Allocate Parking (Dynamic Programming)
7. Exit

## Team Contributions

- Member 1: Vehicle management and hashing
- Member 2: Sorting
- Member 3: Dynamic programming
- Member 4: Repository setup, integration, documentation, and testing

## Note

Vehicle records are stored in memory and are lost when the program exits. The parking allocation algorithm uses total parking-space-hours as its capacity constraint and does not check overlapping vehicle arrival and departure times.
