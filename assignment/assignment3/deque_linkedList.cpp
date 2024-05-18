/// Andrew Souza
/// Comp 210 -- Spring 2024
/// Assignment 3 -- Problem 2

#include <iostream>
#include "LinkedList.h"

using namespace std;

// 2) Implement the Deque ADT using a Linked List based implementation.

class DequeLinkedList : public LinkedList {
    private:
        unsigned int length;
    public:
        DequeLinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        ~DequeLinkedList() {
            
        }
        void PushFront(int x) {
            Node* temp = new Node(x);
            Append(temp);
            length++;
        }
        void PushBack(int x) {
            Node* temp = new Node(x);
            Prepend(temp);
            length++;
        }
        int PopFront() {
            int poppedVal = tail->data;
            tail = tail->previous;
            tail->next = nullptr;
            length--;
            return poppedVal;
        }
        int PopBack() {
            int poppedVal = head->data;
            if (head->next) {
                head->next = (head->next->next);
                head->next->previous = head;
            }
            head = head->next;
            length--;
            return poppedVal;
        }
        int PeekFront() {
            return tail->data;
        }
        int PeekBack() {
            return head->data;
        }
        bool isEmpty() {
            return (length == 0);
        }
        int GetLength() {
            return length;
        }

};

void PrintMenu() {
    cout << "Peek the Front: A";
    cout << "\nPeek the Back: B";
    cout << "\nPop the Front: C";
    cout << "\nPop the Back: D";
    cout << "\nPush to the Front: E";
    cout << "\nPush to the Back: F";
    cout << "\nReturn the length: G";
    cout << "\nInput: ";
}

int main() {
    DequeLinkedList userDeque;
    unsigned int userSize;

    cout << "Enter a deque size: ";
    cin >> userSize;

    for (int i = 0; i < userSize; i++) {
        int input;
        cout << "\nEnter a digit: ";
        cin >> input;
        userDeque.PushBack(input);
    }

    char input;
    PrintMenu();
    cin >> input;
    while (input == 'A' || input == 'B' ||
           input == 'C' || input == 'D' ||
           input == 'E' || input == 'F' ||
           input == 'G') {
        int tempInt;
        switch (input) {
            case 'A':
                cout << "\nFront: " << userDeque.PeekFront();
                break;
            case 'B':
                cout << "\nBack: " << userDeque.PeekBack();
                break;
            case 'C':
                cout << "\nPop Front: " << userDeque.PopFront();
                break;
            case 'D':
                cout << "\nPop Back: " << userDeque.PopBack();
                break;
            case 'E':
                cout << "\nInput digit: ";
                cin >> tempInt;
                userDeque.PushFront(tempInt);
                break;
            case 'F':
                cout << "\nInput digit: ";
                cin >> tempInt;
                userDeque.PushBack(tempInt);
                break;
            case 'G':
                cout << "\nLength: ";
                if (!userDeque.isEmpty()) {
                    cout << userDeque.GetLength();
                } else {
                    cout << "\nEmpty";
                }
            default:
                break;
        }
        cout << "\nPress M to view the menu or press any command: ";
        cin >> input;
        if (input == 'M') {
            PrintMenu();
            cin >> input;
        }
    }

    cout << endl;

    return 0;
}
