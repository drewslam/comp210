#include <iostream>

using namespace std;

// Create a stack using a dynamically allocated array

class ArrayStack {
private:
    int allocationSize;
    int maxSize;
    int* array;
    int length;
    void Resize() {
        int updatedSize = allocationSize * 2;
        int* newArray = new int[updatedSize];
        // For loop to copy values over from array
        for (int i = 0; i < length; i++) {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        allocationSize = updatedSize;
    }
public:
    ArrayStack();
    void Push(int);
    int Pop();
    int Peek();
    bool isEmpty();
    int GetLength();
};

// Default Constructor
ArrayStack::ArrayStack() {
    allocationSize = 0;
    maxSize = 0;
    array = new int[allocationSize];
    length = 0;
}

void ArrayStack::Push(int num) {
    if (length == allocationSize) {
        Resize(allocationSize);
    }

    array[length] = num;
    length++;
}


int ArrayStack::Pop() {
    length--;
    return array[length];
}

int ArrayStack::Peek() {
    return array[length - 1];
}

bool ArrayStack::isEmpty() {
    return (length == 0);
}

int ArrayStack::GetLength() {
    return length;
}

void PrintMenu() {
    cout << "Input 1 to Add an integer to the stack:\n";
    cout << "Input 2 to Pop an integer from the stack:\n";
    cout << "Input 3 to Peek at the top of the stack:\n";
    cout << "Input 4 to find out if the stack is empty:\n";
    cout << "Input 5 to return the length of the stack:\n";
    cout << "Press any number to exit" << endl;
}

int main() {
    ArrayStack stack;
    int size = 3;
    int input = -1;

    PrintMenu();
    cin >> input;

    while (input > 0 && input < 6) {
        switch(input) {
            case 1:
                int temp = -1;
                cout << "Enter a number to push: ";
                cin >> temp;
                stack.Push(temp);
                break;
            case 2:
                cout << "The popped value is: ";
                cout << stack.Pop();
                break;
            case 3:
                cout << "The top of the stack is: ";
                cout << stack.Peek();
                break;
            
            default:

                break;
        }
    }

    return 0;
}
