#include <iostream>
using namespace std;

class Printer2;

class Printer1 {
private:
    static int printing;
public:
    Printer1() {
        printing = 0;
    }
    void set_print(int status) {
        printing = status;
    }

    friend bool inuse(Printer1 p1, Printer2 p2);
};


class Printer2 {
private:
    static int printing;
public:
    Printer2() {
        printing = 0;
    }
    void set_print(int status) {
        printing = status;
    }
    friend bool inuse(Printer1 p1, Printer2 p2);
};

int Printer1::printing = 0;
int Printer2::printing = 0;

bool inuse(Printer1 p1, Printer2 p2) {
    if (Printer1::printing || Printer2::printing) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Printer1 p1;
    Printer2 p2;

    p1.set_print(0);
    p2.set_print(0);

    if (inuse(p1, p2)) {
        cout << "At least one printer is in use.\n";
    } else {
        cout << "Both printers are free.\n";
    }

    return 0;
}