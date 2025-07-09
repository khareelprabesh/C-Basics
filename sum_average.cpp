#include <iostream>
using namespace std;

int main() {
    int numbers[4];
    int sum = 0;
    float average;

    for (int i = 0; i < 4; i++) {
        cout << "Enter a number: ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    average = sum / 4.0;

    cout << "You entered:\n";
    for (int i = 0; i < 4; i++) {
        cout << numbers[i] << endl;
    }

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}
