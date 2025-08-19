# DDS_PROJECT
# C++ Mini-Projects Collection
This repository contains a collection of three separate C++ command-line projects, each designed to demonstrate fundamental programming concepts and data structures.

## 1. Personal Finance Tracker
Project Overview
This is a simple yet effective command-line Personal Finance Tracker written in C++. It allows users to manage their income and expenses, providing features to add, view, sort, filter, and search transactions. The application persists data by saving to and loading from a local text file. A key feature is the ASCII bar chart for visualizing monthly spending.

Features
Add Transactions: Record income or expenses with date, description, and amount.

View Transactions: Display a formatted list of all transactions along with a summary of total income, expenses, and net balance.

Data Persistence: Automatically saves transactions to transactions.txt and loads them on startup.

Sort: Sort transactions by amount in ascending order.

Filter: View transactions of a specific type (e.g., only 'income' or 'expense').

Search: Find specific transactions by searching for keywords in their descriptions.

Monthly Report: Generates a simple ASCII bar chart to visualize total expenses for each month.

Data Structures Used
struct Transaction: A custom data structure to hold the details of each financial entry (date, description, amount, type).

std::vector<Transaction>: A dynamic array is used to store the collection of all transactions.

std::map<std::string, double>: Used to map each month to the total expense amount for that month in the report.

How to Run
Navigate to the PersonalFinanceTracker/src directory.

Compile the main.cpp file: g++ main.cpp -o finance_tracker

Run the executable: ./finance_tracker

Sample Output
Monthly Spending Report (ASCII Chart)

--- Monthly Spending Report (ASCII Chart) ---
2023-10    | ######################################## 1335.50
2023-11    | ###################################### 1200.00

## 2. Smart Parking Lot Management
Project Overview
This C++ application simulates a smart parking lot management system. It uses a linked list to dynamically manage parking slots, allowing cars to be parked and removed. The system keeps track of the total capacity, allocates the first available slot to a new car, and handles overflow scenarios when the lot is full. It also calculates a simple parking fee upon a car's exit based on the duration of its stay.

Features
Dynamic Slot Management: Park cars in the first available slot.

Car Removal: Remove cars by their license plate and calculate the parking fee.

Real-time Status: View the current status of all parking slots.

Capacity Handling: Manages a fixed number of parking slots.

Overflow Notification: Informs the user when the parking lot is full.

Time Tracking: Records the entry time for each car to calculate parking duration.

Data Structures Used
struct ParkingSlot: Represents a node in the linked list, containing car details and a pointer to the next slot.

Singly Linked List: The entire parking lot is represented as a singly linked list of ParkingSlot nodes.

How to Run
Navigate to the SmartParkingLot/src directory.

Compile the source code: g++ main.cpp -o parking_lot

Run the program: ./parking_lot

Sample Output
Viewing Lot Status

--- Parking Lot Status ---
Total Slots: 10
Occupied Slots: 1
Available Slots: 9
--------------------------
Slot 1: OCCUPIED - Plate: ABC-123 (Entry: 2023-10-27 14:30:15)
Slot 2: EMPTY
...
Slot 10: EMPTY

## 3. Expression Calculator
Project Overview
This C++ program is a command-line expression calculator that can evaluate standard mathematical infix expressions. It first converts the user-provided infix expression (e.g., 5 + (10 * 2)) into a postfix expression (e.g., 5 10 2 * +), also known as Reverse Polish Notation (RPN). It then evaluates the postfix expression to compute the final result. The program correctly handles operator precedence and parentheses.

Features
Infix to Postfix Conversion: Implements the Shunting-yard algorithm.

Postfix Evaluation: Evaluates the generated postfix expression.

Operator Precedence: Correctly handles the order of operations.

Parentheses Handling: Properly evaluates expressions within parentheses first.

Error Handling: Catches errors like mismatched parentheses or division by zero.

Supports Floating-Point Numbers.

Data Structures Used
std::stack: The stack is the core data structure used for both the infix-to-postfix conversion (to store operators) and the postfix evaluation (to store operands).

How to Run
Navigate to the ExpressionCalculator/src directory.

Compile the main.cpp file: g++ main.cpp -o calculator

Run the executable: ./calculator

Sample Output
Complex Expression

Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): 3 + 5 * (2 - 8) / 2
Postfix Expression: 3 5 2 8 - * 2 / +
Result: -12
