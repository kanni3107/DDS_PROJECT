#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>

// Structure to hold a single financial transaction
struct Transaction {
    std::string date;        // Format: YYYY-MM-DD
    std::string description;
    double amount;
    std::string type;        // "income" or "expense"
};

// --- Function Prototypes ---
void addTransaction(std::vector<Transaction>& transactions);
void viewTransactions(const std::vector<Transaction>& transactions);
void saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename);
void loadTransactions(std::vector<Transaction>& transactions, const std::string& filename);
void sortTransactions(std::vector<Transaction>& transactions);
void filterTransactions(const std::vector<Transaction>& transactions);
void searchTransactions(const std::vector<Transaction>& transactions);
void displayMonthlyReport(const std::vector<Transaction>& transactions);
void printMenu();

// --- Main Application Logic ---
int main() {
    std::vector<Transaction> transactions;
    const std::string filename = "transactions.txt";
    loadTransactions(transactions, filename); // Load existing data on startup

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character left by std::cin

        switch (choice) {
            case 1:
                addTransaction(transactions);
                break;
            case 2:
                viewTransactions(transactions);
                break;
            case 3:
                sortTransactions(transactions);
                std::cout << "Transactions sorted by amount." << std::endl;
                viewTransactions(transactions);
                break;
            case 4:
                filterTransactions(transactions);
                break;
            case 5:
                searchTransactions(transactions);
                break;
            case 6:
                displayMonthlyReport(transactions);
                break;
            case 7:
                saveTransactions(transactions, filename);
                std::cout << "Transactions saved. Exiting." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << "\n";
    } while (choice != 7);

    return 0;
}

// --- Function Implementations ---

void printMenu() {
    std::cout << "--- Personal Finance Tracker ---" << std::endl;
    std::cout << "1. Add Transaction" << std::endl;
    std::cout << "2. View All Transactions" << std::endl;
    std::cout << "3. Sort Transactions by Amount" << std::endl;
    std::cout << "4. Filter Transactions" << std::endl;
    std::cout << "5. Search Transactions" << std::endl;
    std::cout << "6. View Monthly Spending Report" << std::endl;
    std::cout << "7. Save and Exit" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void addTransaction(std::vector<Transaction>& transactions) {
    Transaction newTransaction;
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin, newTransaction.date);
    std::cout << "Enter description: ";
    std::getline(std::cin, newTransaction.description);
    std::cout << "Enter amount: ";
    std::cin >> newTransaction.amount;
    std::cin.ignore();
    std::cout << "Enter type (income/expense): ";
    std::getline(std::cin, newTransaction.type);

    transactions.push_back(newTransaction);
    std::cout << "Transaction added successfully." << std::endl;
}

void viewTransactions(const std::vector<Transaction>& transactions) {
    if (transactions.empty()) {
        std::cout << "No transactions to display." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(15) << "Date"
              << std::setw(30) << "Description"
              << std::setw(15) << "Amount"
              << std::setw(10) << "Type" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    double totalIncome = 0;
    double totalExpense = 0;

    for (const auto& t : transactions) {
        std::cout << std::left << std::setw(15) << t.date
                  << std::setw(30) << t.description
                  << std::fixed << std::setprecision(2) << std::setw(15) << t.amount
                  << std::setw(10) << t.type << std::endl;
        if (t.type == "income") {
            totalIncome += t.amount;
        } else {
            totalExpense += t.amount;
        }
    }
    std::cout << std::string(70, '-') << std::endl;
    std::cout << "Total Income:  " << totalIncome << std::endl;
    std::cout << "Total Expense: " << totalExpense << std::endl;
    std::cout << "Net Balance:   " << totalIncome - totalExpense << std::endl;
}

void saveTransactions(const std::vector<Transaction>& transactions, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    for (const auto& t : transactions) {
        outFile << t.date << "," << t.description << "," << t.amount << "," << t.type << "\n";
    }
    outFile.close();
}

void loadTransactions(std::vector<Transaction>& transactions, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        // std::cerr << "No existing data file found. Starting fresh." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        Transaction t;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        t.date = line.substr(0, pos1);
        t.description = line.substr(pos1 + 1, pos2 - pos1 - 1);
        t.amount = std::stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
        t.type = line.substr(pos3 + 1);
        transactions.push_back(t);
    }
    inFile.close();
}

void sortTransactions(std::vector<Transaction>& transactions) {
    std::sort(transactions.begin(), transactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.amount < b.amount;
    });
}

void filterTransactions(const std::vector<Transaction>& transactions) {
    std::string filterType;
    std::cout << "Enter type to filter by (income/expense): ";
    std::getline(std::cin, filterType);

    std::cout << std::left << std::setw(15) << "Date"
              << std::setw(30) << "Description"
              << std::setw(15) << "Amount"
              << std::setw(10) << "Type" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto& t : transactions) {
        if (t.type == filterType) {
            std::cout << std::left << std::setw(15) << t.date
                      << std::setw(30) << t.description
                      << std::fixed << std::setprecision(2) << std::setw(15) << t.amount
                      << std::setw(10) << t.type << std::endl;
        }
    }
}

void searchTransactions(const std::vector<Transaction>& transactions) {
    std::string searchTerm;
    std::cout << "Enter description to search for: ";
    std::getline(std::cin, searchTerm);

    std::cout << "Search Results:" << std::endl;
    std::cout << std::string(70, '-') << std::endl;
    bool found = false;
    for (const auto& t : transactions) {
        if (t.description.find(searchTerm) != std::string::npos) {
             std::cout << std::left << std::setw(15) << t.date
                      << std::setw(30) << t.description
                      << std::fixed << std::setprecision(2) << std::setw(15) << t.amount
                      << std::setw(10) << t.type << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No transactions found with that description." << std::endl;
    }
}

void displayMonthlyReport(const std::vector<Transaction>& transactions) {
    std::map<std::string, double> monthlyExpenses;
    for (const auto& t : transactions) {
        if (t.type == "expense") {
            // Extract YYYY-MM from the date
            std::string month = t.date.substr(0, 7);
            monthlyExpenses[month] += t.amount;
        }
    }

    if (monthlyExpenses.empty()) {
        std::cout << "No expense data to generate a report." << std::endl;
        return;
    }

    std::cout << "--- Monthly Spending Report (ASCII Chart) ---" << std::endl;
    
    double maxAmount = 0;
    for(const auto& pair : monthlyExpenses) {
        if (pair.second > maxAmount) {
            maxAmount = pair.second;
        }
    }
    const int MAX_BAR_WIDTH = 50;

    for (const auto& pair : monthlyExpenses) {
        std::cout << std::setw(10) << std::left << pair.first << " | ";
        int barWidth = (maxAmount > 0) ? static_cast<int>((pair.second / maxAmount) * MAX_BAR_WIDTH) : 0;
        for (int i = 0; i < barWidth; ++i) {
            std::cout << "#";
        }
        std::cout << " " << std::fixed << std::setprecision(2) << pair.second << std::endl;
    }
}
