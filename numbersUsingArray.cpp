#include <iostream>
using namespace std;

int main() {
    int numbers[4];

    for (int i = 0; i < 4; i++) {
        cout << "Enter a number: ";
        cin >> numbers[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < 4; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
