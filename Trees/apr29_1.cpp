/// Andrew Souza
/// Comp 210 - Spring 2024
/// Binary Search Tree Lecture Programs
#include <iostream>

using std::cout;

// Implement Binary Search Tree

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int userNum) {
       left = nullptr;
       right = nullptr;
       data = userNum;
    }
};

class Tree {
private:
    Node* root;
      
public:
    Tree() {
       root = nullptr;
    }
    Node* BSTSearch(int key);
    void BSTInsert(int key);
    bool BSTRemove(int key);
    void printLeft();
    void printRight();
    void printTree();
};

// Searching Algorithm
Node* Tree::BSTSearch(int key) {
    // current node starts at root
    Node* curr = root;
    // while loop to keep updating current node to search entire tree
    while (curr != nullptr) {
        if (key == curr->data) {
           return curr; // Found
        } else if (key < curr->data) {
           curr = curr->left;
        } else {
           curr = curr->right;
        }
    }
    return nullptr; // Not found
}

// Insertion Algorithm
void Tree::BSTInsert(int key) {
    Node* node = new Node(key);
    if (root == nullptr) {
        root = node;
    } else {
        Node* curr = root;
        while (curr != nullptr) {
            if (node->data < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = node;
                    curr = nullptr;
                } else {
                    curr = curr->left;
                }
            } else if (node->data > curr->data) {
                if (curr->right == nullptr) {
                    curr->right = node;
                    curr = nullptr;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
}

// Removal Algorithm
bool Tree::BSTRemove(int key) {
   Node* parent = nullptr;
   Node* currentNode = root;
      
   // Search for the node.
   while (currentNode) {
      // Check if currentNode has a matching key.
      if (currentNode->data == key) {
         if (currentNode->left == nullptr && currentNode->right == nullptr) { // Case 1
            if (parent == nullptr) { // Node is root
               root = nullptr;
            }
            else if (parent->left == currentNode) { 
               parent->left = nullptr;
            }
            else {
               parent->right = nullptr;
            }
            delete currentNode;
            return true; // Node found and removed
         }
         else if (currentNode->left && currentNode->right == nullptr) { // Case 2
            if (parent == nullptr) { // Node is root
               root = currentNode->left;
            }
            else if (parent->left == currentNode) {
               parent->left = currentNode->left;
            }
            else {
               parent->right = currentNode->left;
            }
            delete currentNode;
            return true; // Node found and removed
         }
         else if (currentNode->left == nullptr && currentNode->right) { // Case 2
            if (parent == nullptr) { // Node is root
               root = currentNode->right;
            }
            else if (parent->left == currentNode) {
               parent->left = currentNode->right;
            }
            else {
               parent->right = currentNode->right;
            }
            delete currentNode;
            return true; // Node found and removed
         }
         else { // Case 3
            // Find successor (leftmost child of right subtree)
            Node* successor = currentNode->right;
            while (successor->left) {
               successor = successor->left;
            }
            currentNode->data = successor->data; // Copy successor's key to current node
            parent = currentNode;
               
            // Reassigned currentNode and key so that loop continues with new key
            currentNode = currentNode->right;
            key = successor->data;
         }
      }
      else if (currentNode->data < key) { // Search right
         parent = currentNode;
         currentNode = currentNode->right;
      }
      else { // Search left
         parent = currentNode;
         currentNode = currentNode->left;
      }
   }
   return false; // Node not found
}

void Tree::printLeft() {
    // set current node to the root
    Node* curr = root;
    if (root->right == nullptr && root->left == nullptr && root == nullptr) {
        cout << "Tree is empty!\n";
    } else {
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
    }
}

void Tree::printRight() {
    Node* curr = root;
    if (root->right == nullptr && root->left == nullptr && root == nullptr) {
        cout << "Tree is empty!\n";
    } else {
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void Tree::printTree() {
    
}


int main() {
    Tree myTree;

    myTree.BSTInsert(12);
    myTree.BSTInsert(75);
    myTree.BSTInsert(6);
    myTree.BSTInsert(58);
    myTree.BSTInsert(1);
    myTree.BSTInsert(16);
    myTree.BSTInsert(34);

    myTree.BSTRemove(6);
    myTree.BSTRemove(34);

    cout << "\n";

    myTree.printLeft();
    myTree.printRight();

    cout << std::endl;

    return 0;
}
