#include <iostream>
using namespace std;

class Worker {
private:
    int socialNumber;
    string name;
    int yearsOfExperience;
    string currentPosition;
    double salaries[12];
    int salaryCount;

public:

    Worker() : socialNumber(0), yearsOfExperience(0), salaryCount(0) {
        cout << "Въведете текуща длъжност: ";
        getline(cin, currentPosition);
    }

    Worker(int sn, int exp, const string& pos) : socialNumber(sn), yearsOfExperience(exp), currentPosition(pos), salaryCount(0) {}


    void setSocialNumber(int sn) { socialNumber = sn; }
    void setName(const string& n) { name = n; }
    void setYearsOfExperience(int exp) { yearsOfExperience = exp; }
    void setCurrentPosition(const string& pos) { currentPosition = pos; }

    int getSocialNumber() const { return socialNumber; }
    string getName() const { return name; }
    int getYearsOfExperience() const { return yearsOfExperience; }
    string getCurrentPosition() const { return currentPosition; }


    void addSalary(double salary) {
        if (salaryCount < 12) {
            salaries[salaryCount++] = salary;
        } else {
            cout << "Максималният брой заплати е достигнат.\n";
        }
    }

    double averageSalary() const {
        if (salaryCount == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < salaryCount; ++i) {
            sum += salaries[i];
        }
        return sum / salaryCount;
    }

    double minSalary() const {
        if (salaryCount == 0) return 0.0;
        double minSal = salaries[0];
        for (int i = 1; i < salaryCount; ++i) {
            if (salaries[i] < minSal) {
                minSal = salaries[i];
            }
        }
        return minSal;
    }
};
int main() {
    Worker worker1;

    worker1.setSocialNumber(12345);
    worker1.setName("Иван Иванов");
    worker1.setYearsOfExperience(10);


    worker1.addSalary(1200);
    worker1.addSalary(1300);
    worker1.addSalary(1250);
    worker1.addSalary(1280);

    cout << "Име: " << worker1.getName() << endl;
    cout << "Социален номер: " << worker1.getSocialNumber() << endl;
    cout << "Години трудов стаж: " << worker1.getYearsOfExperience() << endl;
    cout << "Текуща длъжност: " << worker1.getCurrentPosition() << endl;
    cout << "Средна заплата: " << worker1.averageSalary() << endl;
    cout << "Минимална заплата: " << worker1.minSalary() << endl;
    return 0;
}
