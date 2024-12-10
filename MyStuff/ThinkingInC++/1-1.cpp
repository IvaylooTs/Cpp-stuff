#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    vector<string> words;
    string word;
    ifstream file("testfile.txt");
    while(file >> word) {
        words.push_back(word);
        cout << word;
    }
    cout << words.size();
    return 0;
}