#include <iostream>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap (arr[j] and arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap (arr[i] and arr[minIndex]);
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() {
    int n = 10;
    int arr[n] = {2,5,3,6,1,22,43,12,64,23};

    cout << "Original array: ";
    displayArray(arr, n);
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    displayArray(arr, n);
    return 0;
}

