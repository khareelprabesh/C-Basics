#include <iostream>
using namespace std;
int main () {
    int l, b, A, P;
    cout << "Enter length ";
    cin >> l;
    cout << "Enter width ";
    cin >> b;
    A = l * b;
    P = 2 * (l + b);
    cout << "Area of rectangle is " << A <<endl; 
    cout << "Perimeter of rectangle is " << P <<endl; 
    return 0;
}