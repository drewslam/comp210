#include <iostream>

using namespace std;

// For every iteration, print sub-list of integers
// Use binary search

int find(int base[], int start, int end, int key) {
    if (start > end) {
        return -1;
    }

    int midpoint = (end + start) / 2;

    for (int i = start; i < end + 1; i++) {
        if (i == end) {
            cout << base[i] << endl;
        } else {
            cout << base[i] << " ";
        }
    }

    if (base[midpoint] < key) {
        return find(base, midpoint + 1, end, key);
    } else if (base[midpoint] > key) {
        return find(base, start, midpoint - 1, key);
    }

    return midpoint;
}

int main() {
    int list[8] = {1, 4, 9, 32, 147, 999, 6006, 10007};
    int key;
    cout << "Enter Key: ";
    cin >> key;
    int found = find(list, 0, 7, key);
    cout << key << " was found at index " << found << endl;

    return 0;
}
