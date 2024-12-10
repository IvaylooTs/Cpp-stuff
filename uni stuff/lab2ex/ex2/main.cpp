#include <iostream>
using namespace std;

class Truck;

class Car {
private:
    int passengers;
    int speed;
public:
    Car(int p, int s) {
        passengers = p;
        speed = s;
    }
    friend int sp_greater(Car c, Truck t);
    friend float timeToTravel(Car c, Truck t, float km);
};

class Truck {
private:
    int weight;
    int speed;
public:
    Truck(int w, int s){
        weight = w;
        speed = s;
    }
    friend int sp_greater(Car c, Truck t);
    friend float timeToTravel(Car c, Truck t, float km);
};

int sp_greater(Car c, Truck t) {
    return c.speed - t.speed;
}
float timeToTravel(Car c, Truck t, float km) {

    float carTime = km / c.speed;
    float truckTime = km / t.speed;
    cout << "Travel time for Car: " << carTime << " hours\n";
    cout << "Travel time for Truck: " << truckTime << " hours\n";
    return carTime;
}

int main() {
    int t;
    Car c1(6, 55), c2(2, 120);
    Truck t1(10000, 55), t2(20000, 72);

    cout << "Comparing c1 and t1:\n";
    t = sp_greater(c1, t1);
    if(t<0) cout << "Truck is faster.\n";
    else if(t==0) cout << "Car and truck speed is the same.\n";
    else cout << "Car is faster.\n";

    float travelTime;
    travelTime = timeToTravel(c2, t2, 240);
    cout << "Time of Car: " << travelTime << " hours\n";
    return 0;
}
