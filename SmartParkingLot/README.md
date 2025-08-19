# Smart Parking Lot Management

## 1. Project Overview

This C++ application simulates a smart parking lot management system. It uses a linked list to dynamically manage parking slots, allowing cars to be parked and removed. The system keeps track of the total capacity, allocates the first available slot to a new car, and handles overflow scenarios when the lot is full. It also calculates a simple parking fee upon a car's exit based on the duration of its stay.

## 2. Features

- **Dynamic Slot Management**: Park cars in the first available slot.
- **Car Removal**: Remove cars by their license plate and calculate the parking fee.
- **Real-time Status**: View the current status of all parking slots, including which are occupied and by which car.
- **Capacity Handling**: Manages a fixed number of parking slots (`TOTAL_SLOTS`).
- **Overflow Notification**: Informs the user when the parking lot is full and cannot accept new cars.
- **Time Tracking**: Records the entry time for each car to calculate parking duration.

## 3. Data Structures Used

- **`struct ParkingSlot`**: A structure that represents a single node in our linked list. Each node contains:
  - `licensePlate`: The license plate of the parked car.
  - `entryTime`: The time the car was parked.
  - `isOccupied`: A boolean flag indicating if the slot is free or taken.
  - `next`: A pointer to the next `ParkingSlot` in the list.
- **Singly Linked List**: The entire parking lot is represented as a singly linked list of `ParkingSlot` nodes. This choice allows for a dynamic representation of slots, although in this implementation, the total number of slots is fixed at the start. It effectively demonstrates dynamic allocation/deallocation of spaces.

## 4. How to Run the Code

### Prerequisites
- A C++ compiler (e.g., G++, Clang).

### Compilation
1.  Navigate to the `src` directory where `main.cpp` is located.
2.  Compile the source code using a C++ compiler.

    ```bash
    g++ main.cpp -o parking_lot
    ```

### Execution
1.  Run the compiled program from your terminal.

    ```bash
    ./parking_lot
    ```

2.  Use the on-screen menu to interact with the parking lot system.

## 5. Sample Run/Output

### Main Menu
```
--- Smart Parking Lot Management ---
1. Park a Car
2. Remove a Car
3. View Parking Lot Status
4. Exit
------------------------------------
Enter your choice: 1
```

### Parking a Car
```
Enter license plate of the car to park: ABC-123
Car with plate 'ABC-123' parked successfully in slot 1.
```

### Viewing Lot Status
```
--- Smart Parking Lot Management ---
1. Park a Car
2. Remove a Car
3. View Parking Lot Status
4. Exit
------------------------------------
Enter your choice: 3

--- Parking Lot Status ---
Total Slots: 10
Occupied Slots: 1
Available Slots: 9
--------------------------
Slot 1: OCCUPIED - Plate: ABC-123 (Entry: 2023-10-27 14:30:15)
Slot 2: EMPTY
Slot 3: EMPTY
...
Slot 10: EMPTY
```

### Removing a Car
```
Enter your choice: 2
Enter license plate of the car to remove: ABC-123
Car with plate 'ABC-123' removed from slot 1.
Parked for: 0.52 hours.
Parking Fee: $1.30
