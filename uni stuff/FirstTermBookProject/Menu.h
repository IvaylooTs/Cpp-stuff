
#include "Textbook.h"
#include "Distributor.h"
#include "Order.h"

#ifndef FIRSTTERMBOOKPROJECT_MENU_H
#define FIRSTTERMBOOKPROJECT_MENU_H

using namespace std;

string getValueAfterLabel(const string& line) {
    size_t pos = line.find(":");
    if (pos != string::npos) {
        // Return the substring after the label (skip the space after the colon)
        return line.substr(pos + 1);
    }
    return "";  // In case there's no colon
}

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
                    //std::numeric_limits<streamsize>::max() gives the maximum value of the streamsize type, which is essentially a very large number.
                    //It ensures that the function can ignore an almost unlimited number of characters until it finds the specified delimiter.

                    //'\n':
                    //This is the delimiter. The function stops discarding characters once it encounters a newline character ('\n')

                    //The function reads and discards up to numeric_limits<streamsize>::max() characters or stops when it encounters a newline ('\n'), whichever comes first.
                    //It's used to clear the input buffer, which may contain leftover or invalid input from a previous cin operation.
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
                // emplace_back constructs the object in place directly within the std::vector.
                // It avoids creating a temporary object and then copying or moving it into the vector, which can save time and memory if the object is large or complex.
                // Using set methods requires first creating an object, calling its setters, and then adding it to the vector.
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
                if (textbooks.empty()) {
                    cout << "No textbooks available.\n";
                    break;
                }
                //size_t: A commonly used unsigned type for indices (e.g., for arrays or containers). It avoids negative indexing errors.
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
                // The & symbol makes chosenDistributor a reference to the Distributor object located at distributors[dChoice - 1].
                //A reference does not create a copy of the object. Instead, it provides a direct alias to the original object in the vector.
                Distributor& chosenDistributor = distributors[dChoice - 1]; // -1 because we count from 1, not from 0

                // We create an order with our chosen distributor as parameter to order constructor
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
                        Textbook& selectedTextbook = textbooks[tChoice - 1];

                        // if an order is done, the amount of copies which we ordered will be deducted from the selected textbook, BOTH in the VECTOR and in the FILE
                        int numCopies;
                        cout << "How many copies of \"" << selectedTextbook.getTitle() << "\" would you like to order? (Available: " << selectedTextbook.getCopies() << "): ";
                        while (!(cin >> numCopies) || numCopies < 1 || numCopies > selectedTextbook.getCopies()) {
                            cout << "Invalid input! Enter a number between 1 and " << selectedTextbook.getCopies() << ": ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        // Deduct the ordered copies from the textbook's available copies
                        selectedTextbook.setCopies(selectedTextbook.getCopies() - numCopies);

                        // Create an instance of selected textbook to the order with the specified number of copies
                        Textbook orderedTextbook = selectedTextbook;
                        orderedTextbook.setCopies(numCopies);
                        order.addTextbook(orderedTextbook);
                    }
                } while (tChoice != 0);

                orders.push_back(order);

                // Save the updated textbooks, distributors, and orders back to the file
                ofstream outFile("data.txt", ios::trunc); // Overwrite the file with updated data
                if (!outFile) {
                    cout << "Error: Could not open file for saving updates.\n";
                } else {
                    //const auto& ensures that each  object is accessed as a reference, without making a copy,
                    //and the const ensures that the object isn't modified during iteration.
                    // Save textbooks
                    for (const auto& tb : textbooks) {
                        if (tb.getCopies() > 0) {
                            outFile << tb; // Only write to file if copies > 0
                        }
                    }

                    // Save distributors
                    for (const auto& d : distributors) {
                        outFile << d;
                    }

                    // Save orders
                    for (const auto& ord : orders) {
                        outFile << ord;
                    }

                    outFile.close();
                    cout << "Data updated in the file after placing the order.\n";
                }

                order.printOrder();
                break;
            }
            case 4: {
                // When we use the option Save Data to File the file is oppened in append mode, so not to delete the previous info
                ofstream outFile("data.txt", ios::app);
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

                // We clear every vector before loading.
                textbooks.clear();
                distributors.clear();
                orders.clear();

                //Every instance of Textbook, Distributor or Order is saved with a title (corresponding to its class) before its information. This title will act as a delimiter
                //when we itterate through the file. When we find a matching title, we load the information after it.
                //The while loop ends on the EOF.
                string type;
                while (inFile >> type) {
                    if (type == "Textbook") {
                        string title, author, isbn, printDate, approvalDate;
                        int edition, copies;
                        bool approved;
                        double pricePerUnit;

                        inFile.ignore();  // Ignore newline after the "Textbook" label

                        // Read and process the title
                        string line;
                        getline(inFile, line);
                        title = getValueAfterLabel(line);

                        // Read and process the author
                        getline(inFile, line);
                        author = getValueAfterLabel(line);

                        // Read edition
                        getline(inFile, line);
                        edition = stoi(getValueAfterLabel(line));  // Convert the string after the label to an integer

                        // Read ISBN
                        getline(inFile, line);
                        isbn = getValueAfterLabel(line);

                        // Read print date
                        getline(inFile, line);
                        printDate = getValueAfterLabel(line);

                        // Read copies
                        getline(inFile, line);
                        copies = stoi(getValueAfterLabel(line));  // Convert the string after the label to an integer

                        // Read price per unit
                        getline(inFile, line);
                        pricePerUnit = stod(getValueAfterLabel(line));  // Convert the string after the label to a double

                        // Read approval status
                        getline(inFile, line);
                        approved = (getValueAfterLabel(line) == "Yes");  // Convert "Yes" to true, anything else to false

                        // Read approval date
                        getline(inFile, line);
                        approvalDate = getValueAfterLabel(line);

                        // Process and add the textbook to your list
                         textbooks.emplace_back(title, author, edition, isbn, printDate, copies, approved, approvalDate, pricePerUnit);

                    } else if (type == "Distributor") {
                        string name, address, phone;

                        inFile.ignore();  // Ignore newline after the "Distributor" label

                        // Read and process the distributor's name
                        string line;
                        getline(inFile, line);
                        name = getValueAfterLabel(line);

                        // Read and process the distributor's address
                        getline(inFile, line);
                        address = getValueAfterLabel(line);

                        // Read and process the distributor's phone number
                        getline(inFile, line);
                        phone = getValueAfterLabel(line);

                        // Process and add the distributor to your list
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
