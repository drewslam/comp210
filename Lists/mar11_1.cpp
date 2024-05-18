#include <iostream>

using namespace std;

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

/*
    null <--> l1 <--> l2 <--> l3 -> null
*/
   
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

    void InsertAfter(Node* currNode, Node* newNode) {
        if (head == nullptr) {         // If head is null  then
            head = newNode;            //  newNode is assigned to
            tail = newNode;            //  head and tail with next
            head->next = tail;         //  and previous set accordingly.
            tail->previous = head;
            tail->next = nullptr;
        } else if (currNode == tail) { // If currNode is tail then
            tail->next = newNode;      //  newNode is appended to the
            newNode->previous = tail;  //  back of the list.
            tail = newNode;
            tail->next = nullptr;
        } else {                            // Otherwise, currNode->next
            newNode->next = currNode->next; //  is assigned to newNode
            currNode->next->previous = newNode;
            newNode->previous = currNode;   //  and newNode->previous
            currNode->next = newNode;       //  is assigned to currNode
        }
    }

    void RemoveAfter(Node* currNode) {
        if (currNode == nullptr && head) {
            Node* toBeRemoved = head; // If nullptr is passed as RemoveAfter's
            head = head->next;        //  argument then the head is removed
            head->previous = nullptr;
            delete toBeRemoved;

            if (head == nullptr) {
                tail = nullptr;
            }
        } else if (currNode->next) {
            Node* toBeRemoved = currNode->next;    // If currNode->next exists
            Node* nextNode = currNode->next->next; //  (is not null), then
            currNode->next = nextNode;             //  currNode->next is removed
            nextNode->previous = currNode;         //  from the list.
            delete toBeRemoved;                    // If currNode->next->next is
            if (nextNode == nullptr) {             //  not null, then it is
                tail = currNode;                   //  assigned to currNode->next
            }
        }
    }

    void PrintHeadToTail() {
        cout << "List: \n";
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << endl;
    }

    void PrintTailToHead() {
        cout << "List Reversed: \n";
        Node* currNode = tail;
        while (currNode != nullptr) {
            cout << currNode->data << " ";
            currNode = currNode->previous;
        }
        cout << endl;
    }
};

LinkedList merge(LinkedList& a, LinkedList& b) {
    LinkedList result;

    Node* currA = a.head;
    Node* currB = b.head;

    while (currA != nullptr && currB != nullptr) {
        cout << currA->data << " " << currB->data << "\n";
        if (currA->data < currB->data) {
            cout << "currB larger\n";
            result.Append(currA);
            currA = currA->next;
        } else {
            cout << "currA larger\n";
            result.Append(currB);
            currB = currB->next;
        }
        result.PrintHeadToTail();
        cout << !currA << " " << !currB << "\n";
    }

    return result;
}

int main() {
    LinkedList test;
    Node* nodeA = new Node(1);
    Node* nodeB = new Node(2);
    Node* nodeC = new Node(3);

    LinkedList test2;
    Node* nodeD = new Node(4);
    Node* nodeE = new Node(5);
    Node* nodeF = new Node(6);

    test.Append(nodeA);
    test.Prepend(nodeB);
    test.InsertAfter(nodeB, nodeC);

    test2.Prepend(nodeD);
    test2.Append(nodeE);
    test2.InsertAfter(nodeD, nodeF);
/*
    test.PrintHeadToTail();

    test2.PrintHeadToTail();
*/
    LinkedList mergedList = merge(test, test2);

    mergedList.PrintHeadToTail();

    return 0;
}
