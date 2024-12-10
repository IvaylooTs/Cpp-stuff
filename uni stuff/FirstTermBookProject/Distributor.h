#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#ifndef FIRSTTERMBOOKPROJECT_DISTRIBUTOR_H
#define FIRSTTERMBOOKPROJECT_DISTRIBUTOR_H

using namespace std;

class Distributor {
private:
    string name, address, phone;
public:

    // Constructor with all parameters
    Distributor(string n, string a, string p) : name(n), address(a), phone(p) {}
    // Constructor with default values
    Distributor() : name(""), address(""), phone("") {}


    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Distributor::name = name;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Distributor::address = address;
    }

    const string &getPhone() const {
        return phone;
    }

    void setPhone(const string &phone) {
        Distributor::phone = phone;
    }

    friend ostream& operator<<(ostream& os, const Distributor& d) {
        os <<"Distributor" << "\n"
        << "Name: " << d.name << "\n"
        <<"Address: " << d.address << "\n"
        <<"Phone: " << d.phone << "\n";
        return os;
    }
};

#endif //FIRSTTERMBOOKPROJECT_DISTRIBUTOR_H
