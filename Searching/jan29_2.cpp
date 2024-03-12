#include <iostream>

using namespace std;

// Recursion
// In two separate functions: Implement Fibonacci, both recursively and nonrecrsively

// Do the nonrecursive method first

// Fibonacci
// 0 + 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 + ...

int Fibonacci(int N) {
    int a = 0;
    int b = 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int main() {
    int input;
    cout << "Enter the number of Fibonacci sequences: ";
    cin >> input;

    cout << Fibonacci(input) << endl;

    return 0;
}
