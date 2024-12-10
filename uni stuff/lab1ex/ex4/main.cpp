#include <iostream>
using namespace std;

class Line{
private:
    int Len;
public:
    Line(int len){
        Len = len;
        for (int i = 0; i<= len; i++){
            cout << "*";
        }
    }

    ~Line(){
        Len = 0;
        cout << "\nDeconstructed.";
    }
};
int main() {
    Line line(30);

    return 0;
}
