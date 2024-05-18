#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

class Node {
public:
    int data;
    Node* next = nullptr;
    Node* previous = nullptr;

    Node(int data) {
        this->data = data;
    }
};

class LinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void Append(Node* newNode) {      // Checks if head is null
        if (head == nullptr) {        // If head is null then head
            head = newNode;           //  and tail are both assigned
            tail = newNode;           //  to newNode
            head->next = tail;
            tail->previous = head;
            tail->next = nullptr;
        } else {
            tail->next = newNode;     // If head is not null then
            newNode->previous = tail;
            tail = newNode;           //  newNode is appended to
            tail->next = nullptr;     //  the end of the list
        }
    }

    void Prepend(Node* newNode) {
        if (head != nullptr) {        // If head is not null then
            newNode->next = head;     //  newNode is pushed to the front
            head->previous = newNode; //  of the list.
            head = newNode;
        } else {
            head = newNode;           // If head is null then head
            tail = newNode;           //  is assigned to newNode
            head->next = tail;
            tail->previous = head;
            tail->next = nullptr;
        }
    }
};

#endif
