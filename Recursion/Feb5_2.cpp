#include <iostream>
using namespace std;
// Pt 1 - Reverse a string recursively

/* char* reverse (char* input, int counter, char* temp) {
    int i = 0;
    while (input[i] != '\0') {
        i++;
    }
    if (counter > i) {
        return temp;
    } else {
        temp[counter] = input[i - counter - 1];
        return reverse(input, counter + 1, temp);
    }
}

int main() {
    char word[7] = "random";
    char result[7];
    cout << reverse(word, 0, result) << endl; 

    return 0;
} */

// Pt 2 - write a recursive form of converting a decimal number to a binary number

int decToBin(int decimal) {
    if (decimal == 0) {
        return 0;
    }
    else {
        cout << decimal % 2;
        return decToBin(decimal / 2);
    }
}

int main() {
    int decimal;

    cout << "Input a number: ";
    cin >> decimal;

    cout << decToBin(decimal) << endl;

    return 0;
}

