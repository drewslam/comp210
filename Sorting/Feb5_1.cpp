#include <iostream>
using namespace std;

// Selection sort / Print array after each interation

void SelectSort(int arr[], int size) {
    int min, temp;

    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = 0; j < size; j++) {
            if (arr[j] < min) {
                min = arr[j];
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[6] = {2, 5, 1, 4, 7, 3};

    SelectSort(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
