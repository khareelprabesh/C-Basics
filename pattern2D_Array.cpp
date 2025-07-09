#include <iostream>
using namespace std;

int main() {
    const int rows = 4;
    const int cols = 5;
    char pattern[rows][cols];

    // Fill the 2D array based on the given pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Define X positions for each row
            if ((i == 0 || i == 2) && j == 2) {
                pattern[i][j] = 'X';
            }
            else if (i == 1 && (j == 1 || j == 3)) {
                pattern[i][j] = 'X';
            }
            else if (i == 3) {
                pattern[i][j] = '*';
            }
            else {
                pattern[i][j] = '*';
            }
        }
    }

    // Display the pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << pattern[i][j];
        }
        cout << endl;
    }

    return 0;
}
