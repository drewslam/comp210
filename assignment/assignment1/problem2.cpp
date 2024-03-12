/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Assignment 1 -- Problem 2

#include <iostream>
using namespace std;

// Write a version of the binary search algorithm that can be used to search a list of strings.  
// Make sure the list is sorted before using the search.  
// Write a driver to test your code.

string StringSearch(string* dictionary, int low, int high, string searchTerm) {
    // Ints low and high represent the low and high index point of the dictionary array
    if (low > high) {
        return "Not Found!";
    }

    // Detects the middle point of the array
    int mid = (low + high) / 2;

    // searchTerm is compared to dictionary at the middle index
    // If searchTerm is alphabetically greater than we call StringSearch again
    //  using mid + 1 as the low parameter.
    if (dictionary[mid] < searchTerm) {
        return StringSearch(dictionary, mid + 1, high, searchTerm);
    } else if (dictionary[mid] > searchTerm) {
        // If searchTerm is lesser than we call StringSearch using
        // mid - 1 as the high parameter.
        return StringSearch(dictionary, low, mid - 1, searchTerm);
    }

    // If the mid index point holds the value of searchTerm
    return dictionary[mid];
}

int main() {
    const int size = 10;
    string dictionary[size] = {"Apple", "Banana", "Centipede", "Dagger", "Elephant", "Fountain", "Georgia", "Hamlet", "Icarus", "Monorail"};
    string searchTerm;
    
    cout << "Search for a word: ";
    cin >> searchTerm;

    cout << "Result: " << StringSearch(dictionary, 0, size, searchTerm) << endl;

    return 0; 
 }
