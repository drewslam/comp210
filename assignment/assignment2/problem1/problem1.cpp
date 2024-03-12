/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Assignment 2 - Problem 1
#include <iostream>
#include "list.h"
using namespace std;

/* 
    Programming Project 14.12.1: ••.

    Turn the linked list implementation into a circular list: 
    Have the previous pointer of the first node point to the last node, 
     and the next pointer of the last node point to the first node. 
    Then remove the last pointer in the List class because the value
     can now be obtained as first->previous. 
    Reimplement the member functions so that they have the same effect as before.
*/

int main() {
    List names;
    string name = "n/a";
    int namesCount = 0;

    cout << "Input a name. type -1 to quit" << endl;
    
    cin >> name;
    while (name != "-1") {
        names.push_back(name);
        namesCount++; 
        cin >> name;
    }
    
    Iterator pos = names.begin();

    for (int i = 0; i < namesCount; i++) {
        cout << pos.get() << endl;
        pos.next();
    }

    return 0;
}
