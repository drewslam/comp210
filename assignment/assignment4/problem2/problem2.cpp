/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Sets, Maps, and Hash Tables Assignment
/// Problem 2
#include <iostream>
#include <iomanip>
#include "HashTable.h"
using namespace std;

// 15.11.7
// Add a previous member function to the hash table iterator in Section 15.5.

int main() {
    HashTable library(10);
    string data;

    cout << "Input some names, input -1 to exit: ";
    getline(cin, data);

    while (data != "-1") {
        library.insert(data);
        getline(cin, data);
    }

    auto iter = library.begin();

    // Prints the list from begin to end
    while (!iter.equals(library.end())) {
        cout << iter.getBI() << " : " << iter.get() << "\n";
        iter.next();
    }

    cout << setw(12) << setfill('-') << "\n";

    // Prints from end to begin
    while (!iter.equals(library.begin())) {
        iter.previous();
        cout << iter.getBI() << " : " << iter.get() << "\n";
    }

    return 0;
}
