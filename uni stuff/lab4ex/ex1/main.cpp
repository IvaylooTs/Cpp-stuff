#include <iostream>
using namespace std;

class Vehicle {
private:
    int num_wheels;
    int range;
public:
    Vehicle(int w, int r){
        num_wheels = w;
        range = r;
    }
    ~Vehicle() = default;
};

class Car:public Vehicle {
private:
    int passengers;
public:
    Car(int p, int w, int r): Vehicle(w, r){
        passengers = p;
    }
    ~Car(){}
};

class Truck:public Vehicle {
private:
    int loadlimit;
public:
    Truck(int ll, int w, int r): Vehicle(w, r){
        loadlimit = ll;
    }
    ~Truck(){}

};
int main() {

    Car c(5, 4, 500);
    Truck t(30000, 12, 1200);
    return 0;
}
