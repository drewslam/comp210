#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;

int main() {
    HashTable library(10);

    library.insert("Math");
    library.insert("English");
    library.insert("History");
    library.insert("Computer Science");
    library.insert("Physics");
    library.insert("Biology");
    library.insert("Sociology");
    library.insert("Physical Education");

    auto iter = library.begin();

    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.next();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";
    iter.previous();
    cout << iter.get() << " " << iter.getBI() << "\n";

    return 0;
}
