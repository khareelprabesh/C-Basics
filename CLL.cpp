// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
// };
// // ----------- a) Initialization -----------
// void initialize(Node *head, int n) {
//     head->data = n;
//     head->next = head;
// }

// // ----------- b-i) Display entire list -----------

// void displayList(Node *head) {
//     Node *cur = head;
// do{
//     cout<<"Data:"<<cur->data<<endl;
//     cur = cur->next;
// }while (cur != head);
// }
// // ----------- b-ii) Add node to rear -----------
// void addNode(Node *head, int n) {
//     Node *cur = head;
//     while (cur->next != head) {
//         cur = cur->next;
//     }

//     Node *newNode = new Node;
//     newNode->data = n;
//     newNode->next = head; // Point to head to maintain circularity
//     cur->next = newNode; // Link the last node to the new node
// }

// // ----------- c-i) Remove node at front -----------

// void removeFront(Node *& head) {
//     Node *cur = head;
//     while (cur->next != head) {
//         cur = cur->next;
//     }

//     cur ->  next = head->next; // Link the last node to the second node
//     Node *oldHead = head; // Store the old head to delete it
//     head = head->next; // Move head to the next node
//     delete oldHead; // Delete the old head node
// }

// // ----------- Main Function For Testing -----------

// int main() {
//     Node *head = new Node;
//     initialize(head, 22);
//     addNode(head, 33);
//     addNode(head, 44);
//     removeFront(head);
//     displayList(head);
// }


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void addEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void removeFront(Node*& head) {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}
