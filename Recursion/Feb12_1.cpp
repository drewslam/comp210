#include <iostream>
using namespace std;

// Write a function that accepts an array of
//  integers and a number indicating the number
//  of elements as args.  
// The function should recursively calc
//  the sum of all the numbers in the array.  
// Demonstrate with a driver.

int sumArray(int* arr, int size) {
    if (size == 1) {
        return arr[size - 1];
    } else {
        return arr[size - 1] + sumArray(arr, size - 1);
    }
}

int main() {
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;

    int* arr = new int[size];
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << sumArray(arr, size) << endl;

    delete[] arr;

    return 0;
}
