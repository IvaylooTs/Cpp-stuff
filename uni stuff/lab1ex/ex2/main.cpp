#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hour;
    int minutes;
    int seconds;

public:

    Time(){
        hour = 0;
        minutes = 0;
        seconds = 0;
    }
    void setTime() {
        do {
            cout << "Enter hour, minutes and seconds: \n";
            cin >> hour >> minutes >> seconds;
            if ((hour < 0 || hour > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59)) {
                cout << "Invalid input. Please enter a valid time.\n";
            }
        } while ((hour < 0 || hour > 23) || (minutes < 0 || minutes > 59) || (seconds < 0 || seconds > 59));
    }


    void getTime(){
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;

        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds
             << (hour >= 12 ? " PM" : " AM") << endl;
    }
};

int main(){
    Time time;
    time.setTime();
    time.getTime();
    return 0;
}