#include <iostream>
#include <cstring>
using namespace std;

enum ZooLocs { ZOOANIMAL, BEAR, PANDA, TIGER, ELEPHANT };

static const char* locTable[] = {
        "Whole zoo area",
        "North B1: brown area",
        "East B1, P area",
        "South B2: tiger area",
        "West C3: elephant area"
};

class ZooAnimal {
    friend void print(ZooAnimal*);
public:
    ZooAnimal(const char* s = "ZooAnimal");
    virtual ~ZooAnimal() { delete[] name; }
    void link(ZooAnimal*);
    virtual void print();
    virtual void isA();
protected:
    char* name;
    ZooAnimal* next;
};

class Bear : public ZooAnimal {
public:
    Bear(const char* s = "Bear", ZooLocs loc = BEAR, const char* sci = "Ursidae");
    ~Bear() { delete[] sciName; }
    void print() override;
    void isA() override;
protected:
    char* sciName;
    ZooLocs ZooArea;
};

class Panda : public Bear {
public:
    Panda(const char* nm, int room, const char* s = "Panda", const char* sci = "Ailuropoda melanoleuca",
          ZooLocs loc = PANDA);
    ~Panda() { delete[] indName; }
    void print() override;
    void isA() override;
protected:
    char* indName;
    int cell;
};

// Нов клас: Tiger
class Tiger : public ZooAnimal {
public:
    Tiger(const char* s = "Tiger", ZooLocs loc = TIGER, int stripes = 0, const char* habitat = "Savannah");
    ~Tiger() { delete[] habitat; }
    void print() override;
    void isA() override;
protected:
    int stripeCount;
    char* habitat;
    ZooLocs ZooArea;
};

// Нов клас: Elephant
class Elephant : public ZooAnimal {
public:
    Elephant(const char* s = "Elephant", ZooLocs loc = ELEPHANT, double tuskLength = 0.0, double weight = 0.0);
    void print() override;
    void isA() override;
protected:
    double tuskLength;
    double weight;
    ZooLocs ZooArea;
};

// Реализация на методи
ZooAnimal::ZooAnimal(const char* s) : next(nullptr) {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
}

void ZooAnimal::link(ZooAnimal* za) {
    za->next = next;
    next = za;
}

void ZooAnimal::isA() {
    cout << "Animal name: " << name << '\n';
}

void ZooAnimal::print() {
    isA();
}

Bear::Bear(const char* s, ZooLocs loc, const char* sci) : ZooAnimal(s), ZooArea(loc) {
    sciName = new char[strlen(sci) + 1];
    strcpy(sciName, sci);
}

void Bear::isA() {
    ZooAnimal::isA();
    cout << "\tScientific name: " << sciName << '\n';
}

void Bear::print() {
    ZooAnimal::print();
    cout << "\tAddress: " << locTable[ZooArea] << '\n';
}

Panda::Panda(const char* nm, int room, const char* s, const char* sci, ZooLocs loc)
        : Bear(s, loc, sci), cell(room) {
    indName = new char[strlen(nm) + 1];
    strcpy(indName, nm);
}

void Panda::isA() {
    Bear::isA();
    cout << "\tIndividual name: " << indName << '\n';
}

void Panda::print() {
    Bear::print();
    cout << "\tCell No: " << cell << '\n';
}

Tiger::Tiger(const char* s, ZooLocs loc, int stripes, const char* habitat)
        : ZooAnimal(s), stripeCount(stripes), ZooArea(loc) {
    this->habitat = new char[strlen(habitat) + 1];
    strcpy(this->habitat, habitat);
}

void Tiger::isA() {
    ZooAnimal::isA();
    cout << "\tStripes: " << stripeCount << '\n';
}

void Tiger::print() {
    ZooAnimal::print();
    cout << "\tHabitat: " << habitat << '\n';
}

Elephant::Elephant(const char* s, ZooLocs loc, double tuskLength, double weight)
        : ZooAnimal(s), ZooArea(loc), tuskLength(tuskLength), weight(weight) {}

void Elephant::isA() {
    ZooAnimal::isA();
    cout << "\tTusk length: " << tuskLength << " meters\n";
    cout << "\tWeight: " << weight << " kg\n";
}

void Elephant::print() {
    ZooAnimal::print();
    cout << "\tAddress: " << locTable[ZooArea] << '\n';
}

void print(ZooAnimal* pz) {
    while (pz) {
        pz->print();
        cout << '\n';
        pz = pz->next;
    }
}

ZooAnimal* headPtr = nullptr;
ZooAnimal circus("Circus animal");
Bear yogi("Little bear", BEAR, "Ursus cartoonus");
Panda yinYang("Yin Yang", 1001, "Big Panda");
Panda rocky("Rocky", 943, "Red Panda", "Ailurus fulgens");
Tiger shereKhan("Shere Khan", TIGER, 108, "Rainforest");
Elephant dumbo("Dumbo", ELEPHANT, 1.5, 5000.0);

ZooAnimal* makelist(ZooAnimal* ptr) {
    ptr = &yinYang;
    ptr->link(&circus);
    ptr->link(&yogi);
    ptr->link(&rocky);
    ptr->link(&shereKhan);
    ptr->link(&dumbo);
    return ptr;
}

int main() {
    cout << "Virtual Function Example\n";
    headPtr = makelist(headPtr);
    print(headPtr);
    return 0;
}
