// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     struct Node * next;
// };
// int main() {
//     Node *head = new Node();
//     Node *second = new Node();

//     head->data = 22;
//     head->next = second;
//     second->data = 33;
//     second->next = NULL;

//     cout << "Data:" << head->data << endl;
//     cout << "Data:" << second->data;
// return 0;
// }





#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void initNode (Node *ptr, int n) {
    ptr->data = n;
    ptr->next = NULL;
}

void addNode (Node *cur, int n) {
    while (cur->next) {
        cur = cur->next;
    }
    Node *newNode = new Node();
    cur->next = newNode;
    newNode->data = n;
    newNode->next = NULL;
}

void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node;
    initNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    
    cout << "All node values: ";
    printList(head);
    return 0;
}
