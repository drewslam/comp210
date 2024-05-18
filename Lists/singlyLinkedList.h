#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

class Node {
    private:
        int data = -1;
        Node* next = nullptr;
    public:
        Node(int data) {
            this->data = data;
        }
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
        void SetData(int data) {
            this->data = data;
        }
        int GetData() const {
            return this->data;
        }
        void SetNext(Node* next) {
            this->next = next;
        }
        Node* GetNext() const {
            return this->next;
        }
};

class SinglyLinkedList {
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
    public:
        SinglyLinkedList(Node* head) {
            this->head = head;
            this->head->SetNext(tail);
        }
        SinglyLinkedList(Node* head, Node* tail) {
            this->head = head;
            this->tail = tail;
            this->head->SetNext(tail);
        }
        void Append(Node* NodeToAdd) {
            if (this->tail != nullptr) {
                this->tail->SetNext(NodeToAdd);
                this->tail = this->tail->GetNext();
            } else if (this->head->GetNext() == nullptr) {
                this->tail = NodeToAdd;
                this->head->SetNext(this->tail);
            }
        }
};

#endif

