#include <iostream>

using namespace std;

// Create a link list with def from 4.6 and include insertAfter and Append function.

class Node {
public:
    Node(int input) {
        this->data = input;
    }
    void SetNext(Node* next) {
        this->next = next;
    }
    int GetData() const {
        return this->data;
    }
    Node* GetNext() const {
        return this->next;
    }

private:
    Node* next = nullptr;
    int data = -1;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
   
public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void Append(Node* node) {
        if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail = node;
            this->tail->SetNext(node);
        }
    }
    void InsertAfter(int targetData, Node* node) {
        Node* current = head;
        while (current->GetNext() != nullptr) {
            if (current->GetData() != targetData) {
                current = current->GetNext();
            }
        }
        if (current->GetData() != targetData) {
            cout << "Data Not Found!" << endl;
            return;
        }
        node->SetNext(current->GetNext());
        current->SetNext(node);
    }
    void RemoveAfter(Node* node) {
        if (node->GetNext() == nullptr) {
            return;
        }
        else {
            Node* toBeRemoved = node->GetNext();
            Node* following = node->GetNext()->GetNext();
            node->SetNext(following);
            delete toBeRemoved;
        }
    }
    virtual ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* toBeRemoved = current;
            current = current->GetNext();
            delete toBeRemoved;
        }
    }
};

int main() {

    return 0;
}
