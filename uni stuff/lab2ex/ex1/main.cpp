#include <iostream>
#include <math.h>

using namespace std;

class Triangle
{
private:
    float a;
    float b;
    float c;
public:
    Triangle(){
        cin >> a >> b >> c;
    }

    float face(){
        float p, s;
        p = (a+b+c) / 2;
        s = sqrt(p*(p-a)*(p-b)*(p-c));
        return s;
    };

    float face(float *p){
        float pp = a+b+c;
        float s;
        *p = pp;
        pp /= 2;
        s = sqrt(pp*(pp-a)*(pp-b)*(pp-c));
        return s;

    }
    void show(){
        cout << "a=" << a << " b=" << b << " c=" << c;
    }

    ~Triangle(){
        cout << "\nObj destructed";
    }
};

int main() {
    Triangle T1;
    T1.show();
    float s;
    s = T1.face();
    cout << "\nFace: " << s;

    Triangle T2;
    Triangle *pointer1;
    pointer1 = &T2;
    s = pointer1->face();
    pointer1 -> show();
    cout << "\nS=" << s;

    Triangle T3;
    T3.show();
    float s3, p;
    s3 = T3.face(&p);
    cout << "\nThe face of triangle2 is s=" << s3 << ", and the perimeter is p=" << p;

    return 0;
}