#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // Variable Declarations
    std::string foodName;
    int itemQuantity;
    double unitPrice;
    char memberChar;
    bool isMember = false;
    std::string cashierNotes;

    // --- INPUT COLLECTION ---
    std::cout << "=== RECEIPT SYSTEM INPUT ===" << std::endl;

    // Read string with spaces

    std::cout << "\n=== MENU ===\n";
    std::cout << std::left << std::setw(15) << "Item"
        << std::setw(10) << "Small(s)"
        << std::setw(10) << "Medium(m)"
        << std::setw(10) << "Large(l)" << std::endl;

    std::cout << "A. Latte       3.50      4.50      5.50\n";
    std::cout << "B. Mocha       4.00      5.00      6.00\n";
    std::cout << "C. Tea         2.00      2.50      3.00\n";
    std::cout << "D. Smoothie    5.00      6.00      7.00\n\n";

    char itemChoice;
    char sizeChoice;

    std::cout << "Select an item (A-D): ";
    std::cin >> itemChoice;

    std::cout << "Select a size (s/m/l): ";
    std::cin >> sizeChoice;

    if (itemChoice == 'A' || itemChoice == 'a') {
        foodName = "Latte";
        if (sizeChoice == 's') unitPrice = 3.50;
        else if (sizeChoice == 'm') unitPrice = 4.50;
        else unitPrice = 5.50;
    }
    else if (itemChoice == 'B' || itemChoice == 'b') {
        foodName = "Mocha";
        if (sizeChoice == 's') unitPrice = 4.00;
        else if (sizeChoice == 'm') unitPrice = 5.00;
        else unitPrice = 6.00;
    }
    else if (itemChoice == 'C' || itemChoice == 'c') {
        foodName = "Tea";
        if (sizeChoice == 's') unitPrice = 2.00;
        else if (sizeChoice == 'm') unitPrice = 2.50;
        else unitPrice = 3.00;
    }
    else if (itemChoice == 'D' || itemChoice == 'd') {
        foodName = "Smoothie";
        if (sizeChoice == 's') unitPrice = 5.00;
        else if (sizeChoice == 'm') unitPrice = 6.00;
        else unitPrice = 7.00;
    }
    else {
        std::cout << "Invalid item selection.\n";
        return 0;
    }


    std::cout << "Enter item quantity: ";
    std::cin >> itemQuantity;


    std::cout << "Is customer a rewards member? (y/n): ";
    std::cin >> memberChar;
    if (memberChar == 'y' || memberChar == 'Y') {
        isMember = true;
    }

    // --- PHASE 4: Handling the cin to getline Buffer Pitfall ---
    // Clear the leftover newline character ('\n') sitting in the stream from 'cin >> memberChar'
    std::cin.ignore(10000, '\n');

    std::cout << "Enter cashier notes: ";
    std::getline(std::cin, cashierNotes);

    // --- PHASE 4: Calculations & Discount Logic ---
    double subtotal = itemQuantity * unitPrice;
    double discount = 0.0;

    if (isMember) {
        discount = subtotal * 0.10; // 10% discount for members
    }

    double discountedSubtotal = subtotal - discount;
    double taxRate = 0.07; // 7% sales tax
    double taxAmount = discountedSubtotal * taxRate;
    double total = discountedSubtotal + taxAmount;

    // --- FORMATTED RECEIPT OUTPUT ---
    std::cout << "\n========================================" << std::endl;
    std::cout << "            STORE RECEIPT               " << std::endl;
    std::cout << "========================================" << std::endl;

    // Apply persistent monetary formatting flags
    std::cout << std::fixed << std::setprecision(2);

    // Main Receipt Items
    std::cout << std::left << std::setw(25) << "Item Name:"
        << std::right << std::setw(15) << foodName << std::endl;


    std::cout << std::left << std::setw(25) << "Quantity x Price:"
        << std::right << std::setw(10) << itemQuantity << " x $"
        << std::setw(3) << unitPrice << std::endl;

    std::cout << "----------------------------------------" << std::endl;

    std::cout << std::left << std::setw(25) << "Subtotal:"
        << std::right << std::setw(13) << "$" << subtotal << std::endl;

    if (isMember) {
        std::cout << std::left << std::setw(25) << "Member Discount (10%):"
            << std::right << std::setw(12) << "-$" << discount << std::endl;
    }

    std::cout << std::left << std::setw(25) << "Tax (7%):"
        << std::right << std::setw(13) << "$" << taxAmount << std::endl;

    std::cout << std::left << std::setw(25) << "TOTAL:"
        << std::right << std::setw(13) << "$" << total << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Cashier Notes: " << cashierNotes << std::endl;
    std::cout << "========================================\n" << std::endl;

    // --- PHASE 4: Inventory Audit Side-by-Side Table ---
    std::cout << "=== INVENTORY AUDIT TABLE ===" << std::endl;

    // Table Header
    std::cout << std::left << std::setw(15) << "Item Name"
        << std::left << std::setw(8) << "Code"
        << std::right << std::setw(8) << "Qty"
        << std::right << std::setw(12) << "Unit Price"
        << std::right << std::setw(12) << "Total Cost" << std::endl;

    std::cout << std::string(55, '-') << std::endl;

    // Table Row Data
    std::cout << std::left << std::setw(15) << foodName
        << std::left << std::setw(8) << sizeChoice
        << std::right << std::setw(8) << itemQuantity
        << std::right << std::setw(11) << "$" << unitPrice
        << std::right << std::setw(11) << "$" << subtotal << std::endl;

    return 0;
}