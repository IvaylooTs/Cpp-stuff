
#include "Textbook.h"
#include "Distributor.h"
#include "Order.h"

#ifndef FIRSTTERMBOOKPROJECT_MENU_H
#define FIRSTTERMBOOKPROJECT_MENU_H

using namespace std;

void menu() {
    vector<Textbook> textbooks;
    vector<Distributor> distributors;
    vector<Order> orders;

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Textbook\n";
        cout << "2. Add Distributor\n";
        cout << "3. Place Order\n";
        cout << "4. Save Data to File\n";
        cout << "5. Load Data from File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        // Input validation
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        switch (choice) {
            case 1: {
                string title, author, isbn, printDate, approvalDate;
                int edition, copies;
                bool approved;
                double pricePerUnit;

                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);

                cout << "Enter edition: ";
                while (!(cin >> edition)) {
                    cout << "Invalid input! Enter an integer for the edition: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter ISBN: ";
                cin >> isbn;

                cout << "Enter print date: ";
                cin >> printDate;

                cout << "Enter copies: ";
                while (!(cin >> copies)) {
                    cout << "Invalid input! Enter an integer for copies: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Approved? (1 for Yes, 0 for No): ";
                while (!(cin >> approved)) {
                    cout << "Invalid input! Enter 1 for Yes or 0 for No: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (approved) {
                    cout << "Enter approval date: ";
                    cin >> approvalDate;
                } else {
                    approvalDate = "N/A";
                }

                cout << "Enter price per unit: ";
                while (!(cin >> pricePerUnit) || pricePerUnit <= 0) {
                    cout << "Invalid input! Enter a positive number for price: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                textbooks.emplace_back(title, author, edition, isbn, printDate, copies, approved, approvalDate, pricePerUnit);
                break;
            }
            case 2: {
                string name, address, phone;

                cout << "Enter distributor name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter phone: ";
                cin >> phone;

                distributors.emplace_back(name, address, phone);
                break;
            }
            case 3: {
                if (distributors.empty()) {
                    cout << "No distributors available.\n";
                    break;
                }

                cout << "Select distributor:\n";
                for (size_t i = 0; i < distributors.size(); ++i) {
                    cout << i + 1 << ". " << distributors[i] << endl;
                }

                int dChoice;
                while (!(cin >> dChoice) || dChoice < 1 || dChoice > (int)distributors.size()) {
                    cout << "Invalid input! Enter a valid distributor number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                Distributor& chosenDistributor = distributors[dChoice - 1];

                Order order(chosenDistributor);
                cout << "Select textbooks to add to the order (enter 0 to stop):\n";
                for (size_t i = 0; i < textbooks.size(); ++i) {
                    cout << i + 1 << ". " << textbooks[i] << endl;
                }

                int tChoice;
                do {
                    while (!(cin >> tChoice)) {
                        cout << "Invalid input! Enter a valid textbook number or 0 to stop: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (tChoice > 0 && tChoice <= (int)textbooks.size()) {
                        order.addTextbook(textbooks[tChoice - 1]);
                    }
                } while (tChoice != 0);

                orders.push_back(order);
                order.printOrder();
                break;
            }
            case 4: {
                ofstream outFile("data.txt");
                if (!outFile.is_open()) {
                    cout << "Error: Could not open file for writing.\n";
                    break;
                }

                for (const auto& tb : textbooks) {
                    outFile << tb;
                }
                for (const auto& d : distributors) {
                    outFile << d;
                }
                outFile.close();
                cout << "Data saved to file.\n";
                break;
            }
            case 5: {
                ifstream inFile("data.txt");
                if (!inFile.is_open()) {
                    cout << "Error: Could not open file!\n";
                    break;
                }
                textbooks.clear();
                distributors.clear();
                orders.clear();

                string type;
                while (inFile >> type) {
                    if (type == "Textbook") {
                        string title, author, isbn, printDate, approvalDate;
                        int edition, copies;
                        bool approved;
                        double pricePerUnit;

                        inFile.ignore(); // Ignore newline
                        getline(inFile, title);
                        getline(inFile, author);
                        inFile >> edition >> isbn >> printDate >> copies;
                        inFile >> pricePerUnit;  // Ensure price is read
                        inFile >> approved;
                        inFile.ignore(); // Ignore newline
                        getline(inFile, approvalDate);


                        textbooks.emplace_back(title, author, edition, isbn, printDate, copies, approved, approvalDate, pricePerUnit);
                    } else if (type == "Distributor") {
                        string name, address, phone;
                        inFile.ignore(); // Ignore newline
                        getline(inFile, name);
                        getline(inFile, address);
                        getline(inFile, phone);

                        distributors.emplace_back(name, address, phone);
                    }
                }
                inFile.close();
                cout << "Data loaded from file.\n";

                // Print loaded data to console
                cout << "\n--- Loaded Textbooks ---\n";
                for (const auto& tb : textbooks) {
                    cout << tb << endl;
                }
                cout << "\n--- Loaded Distributors ---\n";
                for (const auto& dist : distributors) {
                    cout << dist << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);
}


#endif //FIRSTTERMBOOKPROJECT_MENU_H
