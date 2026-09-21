#include <iostream>
#include <string>
#include <iomanip>

int main() {
    // Variable Declarations
    std::string foodName;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    char memberChar;
    bool isMember = false;
    std::string cashierNotes;

    // --- INPUT COLLECTION ---
    std::cout << "=== RECEIPT SYSTEM INPUT ===" << std::endl;

    // Read string with spaces
    std::cout << "Enter food item name: ";
    std::getline(std::cin, foodName);

    std::cout << "Enter item code (single character): ";
    std::cin >> itemCode;

    std::cout << "Enter item quantity: ";
    std::cin >> itemQuantity;

    std::cout << "Enter unit price: $";
    std::cin >> unitPrice;

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

    std::cout << std::left << std::setw(25) << "Item Code:"
        << std::right << std::setw(15) << itemCode << std::endl;

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
        << std::left << std::setw(8) << itemCode
        << std::right << std::setw(8) << itemQuantity
        << std::right << std::setw(11) << "$" << unitPrice
        << std::right << std::setw(11) << "$" << subtotal << std::endl;

    return 0;
}