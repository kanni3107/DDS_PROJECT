#include <iostream>
#include <string>
#include <ctime>

const int TOTAL_SLOTS = 10; // Define the total capacity of the parking lot

// Node structure for the linked list representing a parking slot
struct ParkingSlot {
    std::string licensePlate;
    time_t entryTime;
    bool isOccupied;
    ParkingSlot* next;
};

// --- Function Prototypes ---
void parkCar(ParkingSlot*& head, int& occupiedCount);
void removeCar(ParkingSlot*& head, int& occupiedCount);
void displayLotStatus(ParkingSlot* head, int occupiedCount);
void printMenu();
ParkingSlot* initializeLot(int totalSlots); // Helper to create the list

// --- Main Application Logic ---
int main() {
    ParkingSlot* lotHead = initializeLot(TOTAL_SLOTS);
    int occupiedSlots = 0;

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume newline

        switch (choice) {
            case 1:
                parkCar(lotHead, occupiedSlots);
                break;
            case 2:
                removeCar(lotHead, occupiedSlots);
                break;
            case 3:
                displayLotStatus(lotHead, occupiedSlots);
                break;
            case 4:
                std::cout << "Exiting system." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << "\n";
    } while (choice != 4);

    // Clean up the linked list
    while (lotHead != nullptr) {
        ParkingSlot* temp = lotHead;
        lotHead = lotHead->next;
        delete temp;
    }

    return 0;
}

// --- Function Implementations ---

void printMenu() {
    std::cout << "--- Smart Parking Lot Management ---" << std::endl;
    std::cout << "1. Park a Car" << std::endl;
    std::cout << "2. Remove a Car" << std::endl;
    std::cout << "3. View Parking Lot Status" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

// Initializes the parking lot as an empty linked list
ParkingSlot* initializeLot(int totalSlots) {
    ParkingSlot* head = nullptr;
    ParkingSlot* tail = nullptr;
    for (int i = 0; i < totalSlots; ++i) {
        ParkingSlot* newSlot = new ParkingSlot{ "", 0, false, nullptr };
        if (head == nullptr) {
            head = newSlot;
            tail = newSlot;
        } else {
            tail->next = newSlot;
            tail = newSlot;
        }
    }
    return head;
}

void parkCar(ParkingSlot*& head, int& occupiedCount) {
    if (occupiedCount >= TOTAL_SLOTS) {
        std::cout << "Sorry, the parking lot is full. Overflow parking is not available." << std::endl;
        return;
    }

    std::string plate;
    std::cout << "Enter license plate of the car to park: ";
    std::getline(std::cin, plate);

    // Find the first available slot
    ParkingSlot* current = head;
    int slotNumber = 1;
    while (current != nullptr) {
        if (!current->isOccupied) {
            current->licensePlate = plate;
            current->entryTime = time(0); // Get current time
            current->isOccupied = true;
            occupiedCount++;
            std::cout << "Car with plate '" << plate << "' parked successfully in slot " << slotNumber << "." << std::endl;
            return;
        }
        current = current->next;
        slotNumber++;
    }
}

void removeCar(ParkingSlot*& head, int& occupiedCount) {
    if (occupiedCount == 0) {
        std::cout << "The parking lot is empty. No cars to remove." << std::endl;
        return;
    }

    std::string plate;
    std::cout << "Enter license plate of the car to remove: ";
    std::getline(std::cin, plate);

    ParkingSlot* current = head;
    int slotNumber = 1;
    while (current != nullptr) {
        if (current->isOccupied && current->licensePlate == plate) {
            time_t exitTime = time(0);
            double durationSeconds = difftime(exitTime, current->entryTime);
            double durationHours = durationSeconds / 3600.0;
            double parkingFee = durationHours * 2.50; // Example fee: $2.50 per hour

            std::cout << "Car with plate '" << plate << "' removed from slot " << slotNumber << "." << std::endl;
            std::cout << "Parked for: " << durationHours << " hours." << std::endl;
            std::cout << "Parking Fee: $" << parkingFee << std::endl;

            // Deallocate the slot
            current->isOccupied = false;
            current->licensePlate = "";
            current->entryTime = 0;
            occupiedCount--;
            return;
        }
        current = current->next;
        slotNumber++;
    }

    std::cout << "Car with license plate '" << plate << "' not found in the parking lot." << std::endl;
}

void displayLotStatus(ParkingSlot* head, int occupiedCount) {
    std::cout << "--- Parking Lot Status ---" << std::endl;
    std::cout << "Total Slots: " << TOTAL_SLOTS << std::endl;
    std::cout << "Occupied Slots: " << occupiedCount << std::endl;
    std::cout << "Available Slots: " << TOTAL_SLOTS - occupiedCount << std::endl;
    std::cout << "--------------------------" << std::endl;

    ParkingSlot* current = head;
    int slotNumber = 1;
    while (current != nullptr) {
        std::cout << "Slot " << slotNumber << ": ";
        if (current->isOccupied) {
            char timeBuffer[80];
            strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&current->entryTime));
            std::cout << "OCCUPIED - Plate: " << current->licensePlate << " (Entry: " << timeBuffer << ")" << std::endl;
        } else {
            std::cout << "EMPTY" << std::endl;
        }
        current = current->next;
        slotNumber++;
    }
}
