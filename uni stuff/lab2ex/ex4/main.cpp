#include <iostream>
using namespace std;

class Rectangle {
private:
    float a, b;
public:
    Rectangle(){
        do {
            cin >> a >> b;
        } while ( (a<0) || (b<0));
    };

    float face(){
        return a*b;
    }

    float face(float *p){
        float pp=(a+b)*2;
        *p = pp;
        return a*b;
    }
    ~Rectangle() {
        cout << "Obj destruct";
    };
};

int main() {

    return 0;
}
