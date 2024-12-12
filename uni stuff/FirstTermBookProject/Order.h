#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>

#ifndef FIRSTTERMBOOKPROJECT_ORDER_H
#define FIRSTTERMBOOKPROJECT_ORDER_H

using namespace std;

class Order {
private:
    Distributor distributor;
    //vector that will hold the ordered textbooks
    vector<Textbook> textbooks;


public:
    // Constructor that accepts a Distributor
    Order(Distributor d) : distributor(d) {}

    // Second constructor that initializes the distributor with default values
    Order() : distributor(Distributor("Default Distributor", "Default Address", "000-000-000")) {}

    void addTextbook(const Textbook& tb) {
        textbooks.push_back(tb);
    }

    void printOrder() const {
        cout << "Order for distributor: " << distributor.getName() << endl;
        cout << "Distributor Address: " << distributor.getAddress() << ", Phone: " << distributor.getPhone() << endl;

        double totalCost = 0.0; // Reset totalCost to 0 at the beginning of printOrder() to avoid cumulative total
        for (const auto& tb : textbooks) {
            cout << tb << endl;
            totalCost += tb.getCopies() * tb.getPricePerCopy();
        }

        cout << "Total cost: " << fixed << setprecision(2) << totalCost << " BGN" << endl;
    }
    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Order\n";
        os << "Distributor: " << order.distributor.getName() << "\n";
        os << "Textbooks:\n";
        for (const auto& tb : order.textbooks) {
            os << "Title: " << tb.getTitle() << "\n"
            << "Author: " << tb.getAuthor() << "\n"
            << "ISBN: " << tb.getIsbn() << "\n"
            << "Copies: " << tb.getCopies() << "\n"
            << "Total cost: " << fixed << setprecision(2) << tb.getCopies() * tb.getPricePerCopy() << " BGN" << endl;
            // getcopies and getpricepercopy will work because when we create an order we create a new instance with type Order which we save in the file.
            // So when we enter how many copies we want it multiplies it by the price of the original instance and correct price is calculated.
        }
        os << "--------------\n"; // Separator for orders
        return os;
    }

};

#endif //FIRSTTERMBOOKPROJECT_ORDER_H
