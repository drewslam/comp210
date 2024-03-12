/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Exam 1
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Write a recursive function that prints an integer 
//  with decimal separators. 
// For example, 12345678 should be printed as 12,345,678.

void convertInt(int value, int digitCount, ostringstream& os) {
    if (value == 0) {
        return;
    } else {
        if (digitCount % 3 == 0) {
            os << ",";
        }
        os << value % 10;
        convertInt(value / 10, ++digitCount, os);
    }
}

int main() {
    int input;
    int digitCount = 0;
    string result;
    ostringstream os;

    cout << "Enter an int value: ";
    cin >> input;

    convertInt(input, digitCount, os);

    result = os.str();

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result.at(i);
    }
    cout << endl;
    
    return 0;
}
