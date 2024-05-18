/// Andrew Souza
/// Comp 210 - Spring 2023
/// Exam 2 -- Problem 2
#include <iostream>
#include "NumberList.h"
using namespace std;

// Modify the linked list from the previous problem to
// include a member function named search that returns
// the position of a specific value, x, in the linked list.
// The first node in the list is at position 0, the second node is at 1 and so on.
// If x is not found on the list, the search should return -1.
// Test the new member function using an appropriate driver function.

int main() {
    NumberList list;
    double input = 0.0;

    cout << "Enter numbers. Input a negative number to exit.\n";

    cin >> input;

    while (input >= 0) {
        list.appendNode(input);
        cin >> input;
    }

    cout << "Enter a value to seach for: ";
    cin >> input;

    cout << "You searched for: " << input;
    cout << "\nPosition: " << list.search(input);
    cout << endl;

    return 0;
}
