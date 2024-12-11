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

        double totalCost = 0.0;
        for (const auto& tb : textbooks) {
            cout << tb << endl;
            totalCost += tb.getCopies() * tb.getPricePerCopy();
        }

        // Correct precision setting
        cout << "Total cost: " << fixed << setprecision(2) << totalCost << " BGN" << endl;
    }
    friend ostream& operator<<(ostream& os, const Order& order) {
        os << "Order\n";
        os << "Distributor: " << order.distributor.getName() << "\n";
        os << "Textbooks:\n";
        for (const auto& tb : order.textbooks) {
            os << "  - " << tb.getTitle() << "\n"
            << "Author: " << tb.getAuthor() << "\n"
            << "ISBN: " << tb.getIsbn() << "\n"
            <<", Copies: " << tb.getCopies() << "\n";
        }
        os << "---\n"; // Separator for orders
        return os;
    }

};

#endif //FIRSTTERMBOOKPROJECT_ORDER_H
