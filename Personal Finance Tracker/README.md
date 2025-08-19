# Personal Finance Tracker

## 1. Project Overview

This is a simple yet effective command-line Personal Finance Tracker written in C++. It allows users to manage their income and expenses, providing features to add, view, sort, filter, and search transactions. The application persists data by saving to and loading from a local text file. A key feature is the ASCII bar chart for visualizing monthly spending.

## 2. Features

- **Add Transactions**: Record income or expenses with date, description, and amount.
- **View Transactions**: Display a formatted list of all transactions along with a summary of total income, expenses, and net balance.
- **Data Persistence**: Automatically saves transactions to `transactions.txt` and loads them on startup.
- **Sort**: Sort transactions by amount in ascending order.
- **Filter**: View transactions of a specific type (e.g., only 'income' or 'expense').
- **Search**: Find specific transactions by searching for keywords in their descriptions.
- **Monthly Report**: Generates a simple ASCII bar chart to visualize total expenses for each month.

## 3. Data Structures Used

- **`struct Transaction`**: A custom data structure to hold the details of each financial entry (date, description, amount, type).
- **`std::vector<Transaction>`**: A dynamic array is used to store the collection of all transactions. This allows for efficient storage and iteration.
- **`std::map<std::string, double>`**: Used in the monthly report feature to map each month (as a string, e.g., "2023-10") to the total expense amount for that month.

## 4. How to Run the Code

### Prerequisites
- A C++ compiler (like G++, Clang, or MSVC).
- `make` (optional, but recommended for easy compilation).

### Compilation
1.  Navigate to the `src` directory.
2.  Compile the `main.cpp` file using your C++ compiler.

    ```bash
    g++ main.cpp -o finance_tracker
    ```
    *(On Windows, you might use `g++ main.cpp -o finance_tracker.exe`)*

### Execution
1.  Run the compiled executable from the command line.

    ```bash
    ./finance_tracker
    ```
    *(On Windows, you might use `finance_tracker.exe`)*

2.  Follow the on-screen menu to manage your finances.

## 5. Sample Run/Output

Here is an example of what a user session might look like.

### Main Menu
```
--- Personal Finance Tracker ---
1. Add Transaction
2. View All Transactions
3. Sort Transactions by Amount
4. Filter Transactions
5. Search Transactions
6. View Monthly Spending Report
7. Save and Exit
--------------------------------
Enter your choice: 1
```

### Adding a Transaction
```
Enter date (YYYY-MM-DD): 2023-10-25
Enter description: Groceries
Enter amount: 75.50
Enter type (income/expense): expense
Transaction added successfully.
```

### Viewing All Transactions
```
Date           Description                   Amount         Type
----------------------------------------------------------------------
2023-10-01     Paycheck                      2500.00        income
2023-10-05     Rent                          1200.00        expense
2023-10-15     Internet Bill                 60.00          expense
2023-10-25     Groceries                     75.50          expense
2023-11-01     Paycheck                      2500.00        income
2023-11-05     Rent                          1200.00        expense
----------------------------------------------------------------------
Total Income:  5000.00
Total Expense: 2535.50
Net Balance:   2464.50
```

### Monthly Spending Report (ASCII Chart)
```
--- Monthly Spending Report (ASCII Chart) ---
2023-10    | ######################################## 1335.50
2023-11    | ###################################### 1200.00
