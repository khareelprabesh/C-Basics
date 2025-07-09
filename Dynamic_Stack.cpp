#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

// Question b (i):
bool isEmpty() {
    return top == NULL;
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty.\n" << endl;
        return -1; // or throw an exception
    }
    return top->data;
}

// Question b (ii):
void displayStack(){
    Node *cur = top;
    cout << "Stack: ";
    while (cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Question c (i):
void push(int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = top; // Point to the previous top
    top = newNode; // Update top to the new node
};

// Question c (ii):
void pop() {
    if (top == NULL) return;
    Node* temp = top;
    top = top->next; // Move top to the next node
    delete temp; // Delete the old top node
}

int main(){
    peek();
    push(10);
    push(20);
    push(30);
    pop();
    displayStack();
    return 0;
}