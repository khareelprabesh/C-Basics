#include <iostream>
using namespace std;

int main() {
    
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;
    cout << "3. Pointer Arithmetic:" << endl;
    cout << "Address of array \n" << &arr << endl;
    cout << "Address of array \n" << &arr[0] << endl;
    cout << "Address pointed by the pointer \n" << arrPtr << endl;
    cout << "Value pointed by the pointer  \n" << *arrPtr << endl;
    return 0;
}