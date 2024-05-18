/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Set, Maps, and Hash Tables Assignment
/// Problem 1
#include <iostream>
#include <unordered_set>
#include <fstream>
using namespace std;

// 15.11.1
// Write a program that counts how often each word occurs in a text file.
// Use an unordered_multiset<string>.

int main() {
    string fileName;
    ifstream inFS;
    unordered_multiset<string> wordCount;

    cout << "Input your file name: ";
    cin >> fileName;

    inFS.open(fileName);

    if (!inFS.fail()) {
        string data;
        while (!inFS.eof()) {
            inFS >> data;
            wordCount.insert(data);
        }
    }

    inFS.close();

    cout << "Word count: \n";
    string last;
    for (auto i = wordCount.begin(); i != wordCount.end(); i++) {
        if (last != *i) {
            cout << *i << " - " << wordCount.count(*i) << "\n";
        }
        last = *i;
    }

    return 0;
}
