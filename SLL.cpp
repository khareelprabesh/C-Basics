#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// a) Initialize the first node
void initNode(Node *tmpHead, int n) {
    tmpHead->data = n;
    tmpHead->next = NULL;
}

// b.i) Display all nodes
void displayList(Node *cur) {
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// b.ii) Add node to rear
void addNode(Node *cur, int n) {
    while (cur->next) {
        cur = cur->next;
    }
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    cur->next = newNode;
}

// c.i) Add node to front
void addFront(Node **tmpHead, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *tmpHead;
    *tmpHead = newNode;
}

// c.ii) Remove node from rear
void removeNode(Node *cur) {
    if (cur->next == NULL) {
        cout << "Single Node!" << endl;
    } else {
        while (cur->next->next) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = NULL;
    }
}

// d.i) Remove node from front
void removeFront(Node **tmpHead) {
    if ((*tmpHead)->next == NULL) {
        cout << "Single Node!" << endl;
    } else {
        Node *oldHead = *tmpHead;
        *tmpHead = oldHead->next;
        delete oldHead;
    }
}

// d.ii) Count total nodes
int getTotalNode(Node *cur) {
    int counter = 0;
    while (cur) {
        counter++;
        cur = cur->next;
    }
    return counter;
}

int main() {
    Node *head = new Node;
    initNode(head, 22);         // Initialize with 22

    addNode(head, 33);          // Add 33 to rear
    addNode(head, 44);          // Add 44 to rear

    addFront(&head, 11);        // Add 11 to front
    removeNode(head);           // Remove rear node
    removeFront(&head);         // Remove front node
    displayList(head);          // Display after front remove

    cout << "COUNT = " << getTotalNode(head) << endl; // Count nodes
    return 0;
}
