#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<char> stck;

public:
    void push(char character) {
        stck.push(character);
    }

    void pop() {
        if (!stck.empty()) {
            stck.pop();
        }
    }

    bool isEmpty() const {
        return stck.empty();
    }

    char top() const {
        if (!stck.empty()) {
            return stck.top();
        }
        return '\0';
    }

    void loadstack(int upper) {
        if (upper == 1) {
            for (char c = 'a'; c <= 'z'; c++)
                push(c);
        } else {
            for (char c = 'A'; c <= 'Z'; c++)
                push(c);
        }
    }


    void printStack() {
        while (!stck.empty()) {
            cout << stck.top() << " ";
            stck.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s1;
    s1.loadstack(1);
    s1.printStack();

    Stack s2;
    s2.loadstack(0);
    s2.printStack();

    return 0;
}