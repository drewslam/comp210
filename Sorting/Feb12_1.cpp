#include <iostream>
using namespace std;
// Code a bubble sort
// at each iteration print out the array - an array of 7

void print_array(int array[]) {
    for (int i = 0; i < 7; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Merge Sort from book

void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize]; // Dynamically allocates temporary
                                             // array for merged numbers
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position
      
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
      }
      mergePos++;
   }
      
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
   }
   
   // Copy merged numbers back to numbers
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }
   
   // Free temporary array
   delete[] mergedNumbers;
}
   
void MergeSort(int* numbers, int startIndex, int endIndex, int& iterations) {
   if (startIndex < endIndex) {
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numbers, startIndex, mid, iterations);
      MergeSort(numbers, mid + 1, endIndex, iterations);
            
      // Merge left and right partition in sorted order
      Merge(numbers, startIndex, mid, endIndex);
      cout << "Iteration #" << ++iterations << ": ";
      print_array(numbers);
   }
}


void bubble_sort(int array[], int& iterations) {
    int sorted = 0;
    int i = 0;
    while (sorted != 7) {
        if (i > 6) {
            i = 0;
        }
        if (array[i + 1] > array[i]) {
            sorted++;
        } else {
            int temp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = temp;
        }
        i++;
        cout << "Iteration #" << ++iterations << ":\t";
        print_array(array);
    }
}

int main() {
    int arr1[7] = {5,-8,10,216,17,0,1};
    int arr2[7] = {5,-8,10,216,17,0,1};
    
    int iterations1 = 0;
    int iterations2 = 0;
    
    bubble_sort(arr1, iterations1); 
    MergeSort(arr2, 0, 7, iterations2);    
    // print_array(arr);

    return 0;
}
