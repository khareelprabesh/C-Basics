#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Binary Search for Exponential Search
int binarySearchRange(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential Search
int exponentialSearch(const vector<int>& arr, int target) {
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < arr.size() && arr[i] <= target)
        i *= 2;

    return binarySearchRange(arr, i / 2, min(i, (int)arr.size() - 1), target);
}

int main() {
    int N, target;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<int> arr(N);
    srand(time(0));

    cout << "\nGenerated Random Numbers:\n";
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 1000;  // random numbers between 0–999
        cout << arr[i] << " ";
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    cout << "\n\nSorted Array:\n";
    for (int num : arr)
        cout << num << " ";

    cout << "\n\nEnter number to search: ";
    cin >> target;

    // Binary Search with time
    auto start_binary = high_resolution_clock::now();
    int index_binary = binarySearch(arr, target);
    auto stop_binary = high_resolution_clock::now();
    auto duration_binary = duration_cast<microseconds>(stop_binary - start_binary);

    // Exponential Search with time
    auto start_expo = high_resolution_clock::now();
    int index_expo = exponentialSearch(arr, target);
    auto stop_expo = high_resolution_clock::now();
    auto duration_expo = duration_cast<microseconds>(stop_expo - start_expo);

    // Output Results
    cout << "\n\n--- Binary Search Result ---";
    if (index_binary != -1)
        cout << "\nElement found at index: " << index_binary;
    else
        cout << "\nElement not found.";
    cout << "\nTime taken: " << duration_binary.count() << " microseconds";

    cout << "\n\n--- Exponential Search Result ---";
    if (index_expo != -1)
        cout << "\nElement found at index: " << index_expo;
    else
        cout << "\nElement not found.";
    cout << "\nTime taken: " << duration_expo.count() << " microseconds\n";

    return 0;
}
