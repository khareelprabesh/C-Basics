#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Quick Sort Functions
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Merge Sort Functions
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Enter the number of elements to sort: ";
    cin >> N;

    vector<int> original(N);
    srand(time(0));

    cout << "\nGenerated Random Numbers:\n";
    for (int i = 0; i < N; ++i) {
        original[i] = rand() % 1000;
        cout << original[i] << " ";
    }

    // Quick Sort
    vector<int> arrQuick = original;
    auto startQ = high_resolution_clock::now();
    quickSort(arrQuick, 0, N - 1);
    auto stopQ = high_resolution_clock::now();
    auto durationQ = duration_cast<microseconds>(stopQ - startQ);

    // Merge Sort
    vector<int> arrMerge = original;
    auto startM = high_resolution_clock::now();
    mergeSort(arrMerge, 0, N - 1);
    auto stopM = high_resolution_clock::now();
    auto durationM = duration_cast<microseconds>(stopM - startM);

    // Output
    cout << "\n\n--- Quick Sort Result ---\nSorted Array (First 10): ";
    for (int i = 0; i < min(10, N); ++i)
        cout << arrQuick[i] << " ";
    cout << "\nTime taken: " << durationQ.count() << " microseconds";

    cout << "\n\n--- Merge Sort Result ---\nSorted Array (First 10): ";
    for (int i = 0; i < min(10, N); ++i)
        cout << arrMerge[i] << " ";
    cout << "\nTime taken: " << durationM.count() << " microseconds\n";

    return 0;
}
