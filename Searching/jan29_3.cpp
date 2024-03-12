#include <iostream>

using namespace std;

// Create a power function recursively
double pow(int num, int power) {
    if (power == 0) {
        return 1;
    } else if (power == 1) {
        return num;
    } else if (power > 1) {
        return num * pow(num, power - 1);
    } else {
        return (1.0 / (num)) * pow(num, power + 1);
    }
}

// Recursive Factorial Function
int factorial(int num) {
    if (num == 0) {
        cout << " = ";
        return 1;
    } else {
        cout << num;
        if (num > 1) {
            cout << " * ";
        }
        return num * factorial(num - 1);
    }
}

int main() {
    int num;
    int power;

    cin >> num >> power;

    cout << pow(num, power) << endl;

    cout << factorial(num) << endl;

    return 0;
}
