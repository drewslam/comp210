#include <iostream>

//create your own bubble sort, however at each iteration print out the array - an array of 7

using namespace std;

void print_array(int array[]) {
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl << "Printed array" << endl << endl;
}


void bubble_sort(int array[]) {
    cout <<"Initial Unsorted Array:" << endl;
    print_array(array);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
        print_array(array);
        cout << endl;
    }
}


int main () {

    int array[7] = { 5, -8, 10, 216, 17, 0, 1};

    bubble_sort(array);

    return 0;
}
