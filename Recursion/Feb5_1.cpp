#include <iostream>
using namespace std;

// Implement Binary Search using recursion

// Print each subarray

int BinarySearch(int arr[], int start, int end, int key) {
    int position = start;
    if (start > end) {
        return -1;
    }
    int midpoint = (start + end) / 2;
    while (position < end) {
        cout << arr[position] << " ";
        position++;
    }
    cout << endl;
    if (key == arr[midpoint]) {
        return arr[midpoint];
    } else {
        if (key > arr[midpoint]) {
            return BinarySearch(arr, midpoint + 1, end, key);
        } else {
            return BinarySearch(arr, start, midpoint - 1, key);
        }
    }
}

int main() {
    int size = -1;
    int search = -1;

    cout << "Enter a size for your array: ";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        int* num = new int;
        int temp;
        if (i > 0) {
            cout << "Previous val: " << arr[i - 1] << endl;
        }
        cout << "Please enter an number larger than the previous: " << endl;
        cin >> temp;
        num = &temp;
        arr[i] = *num;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Input a value to search for: " << endl;
    cin >> search;

    int result = BinarySearch(arr, 0, size, search);
    cout << "Key = " << search << " : Result = " << result << endl;

    return 0;
}
