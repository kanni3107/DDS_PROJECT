# C++ Mini-Projects Collection 👋
This repository contains a collection of three separate C++ command-line projects, each designed to demonstrate fundamental programming concepts and data structures.

## 💰 1. Personal Finance Tracker
### Project Overview
 A simple yet effective command-line tool to manage your income and expenses. It persists data locally and can generate a simple ASCII bar chart to visualize your monthly spending habits.

### Features
📝 Add Transactions: Record income or expenses with date, description, and amount.

📊 View Transactions: Display a formatted list of all transactions and a net balance summary.

💾 Data Persistence: Automatically saves transactions to transactions.txt and loads them on startup.

↕️ Sort: Sort transactions by amount in ascending order.

🔍 Filter & Search: View transactions of a specific type or find them by keywords.

📈 Monthly Report: Generates an ASCII bar chart to visualize monthly expenses.

Data Structures Used
struct Transaction: A custom structure to hold the details of each financial entry.

std::vector<Transaction>: A dynamic array to store the collection of all transactions.

std::map<std::string, double>: Used to map each month to its total expense for the report.

How to Run
Navigate to the PersonalFinanceTracker/src directory.

Compile the main.cpp file: g++ main.cpp -o finance_tracker

Run the executable: ./finance_tracker

Sample Output
Monthly Spending Report (ASCII Chart)

--- Monthly Spending Report (ASCII Chart) ---
2023-10    | ######################################## 1335.50
2023-11    | ###################################### 1200.00

## 🅿️ 2. Smart Parking Lot Management
Project Overview
This application simulates a smart parking lot management system using a linked list. It handles parking, removal, and status tracking for a fixed number of slots, and even calculates a parking fee based on the duration of the stay.

### Features
🚗 Dynamic Slot Management: Park cars in the first available slot.

💳 Car Removal & Fee Calculation: Remove cars by license plate and calculate the parking fee.

🚦 Real-time Status: View the current status of all parking slots (occupied or empty).

🈵 Capacity Handling: Manages a fixed number of parking slots and notifies when full.

⏱️ Time Tracking: Records the entry time for each car.

#### Data Structures Used
struct ParkingSlot: Represents a node in the linked list.

Singly Linked List: The entire parking lot is represented as a singly linked list of ParkingSlot nodes.

** How to Run **
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

## 🧮 3. Expression Calculator
Project Overview
A command-line calculator that evaluates standard mathematical infix expressions. It uses the Shunting-yard algorithm to convert the expression to postfix (RPN) and then calculates the result, correctly handling operator precedence and parentheses.

### Features
🔄 Infix to Postfix Conversion: Implements the Shunting-yard algorithm.

🧮 Postfix Evaluation: Evaluates the generated postfix expression to get the final result.

🥇 Operator Precedence: Correctly handles the order of operations (*, / before +, -).

🧠 Parentheses Handling: Properly evaluates expressions within parentheses first.

⚠️ Error Handling: Catches errors like mismatched parentheses or division by zero.

🔢 Supports Floating-Point Numbers.

Data Structures Used
std::stack: The core data structure for both the infix-to-postfix conversion and the final postfix evaluation.

** How to Run **
Navigate to the ExpressionCalculator/src directory.

Compile the main.cpp file: g++ main.cpp -o calculator

Run the executable: ./calculator

Sample Output
Complex Expression

Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): 3 + 5 * (2 - 8) / 2
Postfix Expression: 3 5 2 8 - * 2 / +
Result: -12
