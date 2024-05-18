/// Andrew Souza
/// Comp 210 - Spring 2023
/// Exam 2 -- Problem 1
#include <iostream>
#include "NumberList.h"
using namespace std;

// Please use the attached code and implement the display function.
// The function should display all the values of the linked list.
// Test the class by starting with an empty list, adding some elements,
// then printing the resulting list output.


int main() {
    NumberList list;
    double input = 0.0;

    cout << "Enter numbers. Input a negative number to exit.\n";

    cin >> input;

    while (input >= 0) {
        list.appendNode(input);
        cin >> input;
    }

    cout << "You entered:\n";

    list.displayList();

    cout << endl;

    return 0;
}
