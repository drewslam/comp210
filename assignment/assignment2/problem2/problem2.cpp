/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Assignment 2 - Problem 2
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

/*
    Practice Exercise 14.11.5: ••.

    Write a function merge that merges two lists into one,
     alternating elements from each list until the end of
     one of the lists has been reached, then appending the
     remaining elements of the other list. 
    For example, merging the lists containing A B C and
     D E F G H should yield the list A D B E C F G H.
*/

List merge(List a, List b, int count) {
    Iterator pos1 = a.begin();              // 2 Iterators are initialized for each list
    Iterator pos2 = b.begin();
    List result;                            // A result list is defined to hold the value of both lists
    int i = 0;

    do {
        if (!pos1.equals(a.end())) {        // As long as each Iterator holds a value then the value is pushed
            result.push_back(pos1.get());   // into the result list
            pos1.next();
        }
        if (!pos2.equals(b.end())) {
            result.push_back(pos2.get());
            pos2.next();
        }
        i++;
    } while (i != count);                   // i increases until it equals the count value

    return result;
}

int main() {
    List list1;
    List list2;
    int count = 0;

    list1.push_back("A");
    list1.push_back("B");
    list1.push_back("C");

    list2.push_back("D");
    list2.push_back("E");
    list2.push_back("F");
    list2.push_back("G");
    list2.push_back("H");

    // Each linked list is looped through to increase the value of count
    // until we reach the size of our result list    
    for (Iterator pos = list1.begin(); !pos.equals(list1.end()); pos.next()) {
      count++;
    }

    for (Iterator pos = list2.begin(); !pos.equals(list2.end()); pos.next()) {
      count++;
    }

    List list3 = merge(list1, list2, count);
    
    for (Iterator pos = list3.begin(); !pos.equals(list3.end()); pos.next()) {
      cout << pos.get() << " ";
    }
    cout << endl;

    return 0;
}
