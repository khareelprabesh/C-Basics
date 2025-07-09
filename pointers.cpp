#include <iostream>
using namespace std;

int main() {
    
    // Basic Pointer Declaration and Initialization
    int num = 10;
    int* ptr = &num;
    
    cout << "1. Basic Pointer Usages:" << endl;
    cout << "Value of num:" << num << endl;
    cout << "Address of num:" << &num << endl;
    cout << "Value of ptr:" << ptr << endl;
    cout << "Value ptr points to:" << *ptr << endl << endl;
    
    // Modifing Value through Pointer
    *ptr = 20;
    cout << "2. Modifying through Pointer:" << endl;
    cout << "New value of num:" << num << endl;
    return 0;
}