#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string foodName;
	char itemCode;
	int itemQuantity;
	double unitPrice;
	bool isMember;

	cout << "============RECIPT SYSTEM============" << endl;
	cout << "Food Name: ";
	getline(cin, foodName);
	cout << "Item Code (Single Characters): ";
	cin >> itemCode;
	cout << "Item Quantity: ";
	cin >> itemQuantity;
	cout << "Unit Price: ";
	cin >> unitPrice;
	cout << "Is Member? (y/n): ";
	cin >> isMember;
	isMember = (isMember == 'y' || isMember == 'Y');

	double subtotal = itemQuantity * unitPrice;
	double taxAmount = subtotal * 0.07; // 7% tax rate
	double total = subtotal + taxAmount;

	// --- PHASE 2: Formatted Receipt Output ---
	std::cout << "\n========================================" << std::endl;
	std::cout << "            STORE RECEIPT               " << std::endl;
	std::cout << "========================================" << std::endl;

	// Persistent monetary formatting flags
	std::cout << std::fixed << std::setprecision(2);

	// Monospaced alignment using std::setw, std::left, std::right
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

	std::cout << std::left << std::setw(25) << "Tax (7%):"
		<< std::right << std::setw(13) << "$" << taxAmount << std::endl;

	std::cout << std::left << std::setw(25) << "TOTAL:"
		<< std::right << std::setw(13) << "$" << total << std::endl;

	std::cout << "========================================\n" << std::endl;

	return 0;

}
