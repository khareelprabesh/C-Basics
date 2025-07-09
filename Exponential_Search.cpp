#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Binary search used inside Exponential Search
int binarySearch(const vector<int>& arr, int left, int right, int target) {
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

    return binarySearch(arr, i / 2, min(i, (int)arr.size() - 1), target);
}

int main() {
    int N, target;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<int> arr(N);
    srand(time(0));

    cout << "\nGenerated Random Numbers:\n";
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 1000;
        cout << arr[i] << " ";
    }

    sort(arr.begin(), arr.end());

    cout << "\n\nSorted Numbers:\n";
    for (int num : arr)
        cout << num << " ";

    cout << "\n\nEnter number to search: ";
    cin >> target;

    auto start = high_resolution_clock::now();
    int index = exponentialSearch(arr, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (index != -1)
        cout << "\nElement found at index: " << index << endl;
    else
        cout << "\nElement not found in the array.\n";

    cout << "Time taken for Exponential Search: " << duration.count() << " microseconds\n";

    return 0;
}
