#include <iostream>

using namespace std;

// Implement a queue using a doubly linked list

class Node {
private:
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
public:
    Node();
    Node(int);
    Node(int, Node*);
    void SetValue(int);
    int GetValue();
    void SetNext(Node*);
    Node* GetNext();
    void SetPrev(Node*);
    Node* GetPrev();
};

Node::Node() {
    value = -1;
}

Node::Node(int input) {
    value = input;
}

Node::Node(int input, Node* next) {
    value = input;
    next = next;
}

void Node::SetValue(int input) {
    value = input;
}

int Node::GetValue() {
    return value;
}

void Node::SetNext(Node* next) {
    next = next;
}

Node* Node::GetNext() {
    return next;
}

void Node::SetPrev(Node* prev) {
    prev = prev;
}


Node* Node::GetPrev() {
    return prev;
}

class LinkedListQueue {
private:
    Node* head;
    Node* tail;
    int length = 0;
public:
    LinkedListQueue() { 
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedListQueue() {};
    void Push(int);
    int Pop();
    int Peek();
    bool isEmpty();
    int GetLength();
};

void LinkedListQueue::Push(int input) {
    Node* temp = new Node(input);
    if (head == nullptr) {
        head = temp;
        tail = head;
    } else {
        head->SetPrev(temp);
        temp->SetNext(head);
        head = temp;
    }
    length++;
}

int LinkedListQueue::Pop() {
    int poppedVal = tail->GetValue(); 
    tail = tail->GetPrev();
    tail->SetNext(nullptr);
    length--;
    return poppedVal;
}

int LinkedListQueue::Peek() {
    return tail->GetValue();
}

bool LinkedListQueue::isEmpty() {
    return (length == 0);
}

int LinkedListQueue::GetLength() {
    return length;
}

void PrintMenu() {
    cout << "\nInput 1 to push a value:\n";
    cout << "Input 2 to pop from the tail:\n";
    cout << "Input 3 to peek the tail:\n";
    cout << "Input 4 for the length:\n";
    cout << "Input any other value to exit:" << endl;
}

int main() {
    LinkedListQueue queue;
    int input = -1;

    PrintMenu();

    cin >> input;

    while (input >= 1 && input <= 4) {
        switch (input) {
            default: 
                break;
            case 4:
                if (queue.isEmpty()) {
                    cout << "\nEmpty!";
                } else {
                    cout << "\nLength: " << queue.GetLength();
                }
                break;
            case 3:
                if (!queue.isEmpty()) {
                    cout << queue.Peek();
                } else {
                    cout << "\nEmpty!";
                }
                break;
            case 2:
                if (!queue.isEmpty()) {
                    cout << queue.Pop();
                }
                break;
            case 1:
                cin >> input;
                queue.Push(input);
        }
        PrintMenu();
        cin >> input;
    }

    return 0;
}
