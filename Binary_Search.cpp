#include <iostream>
#include <vector>
#include <algorithm>  // for sort
#include <cstdlib>    // for rand(), srand()
#include <ctime>      // for time()
#include <chrono>     // for runtime measurement

using namespace std;
using namespace std::chrono;

// Binary Search Function
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // not found
}

int main() {
    int N, target;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<int> arr(N);
    srand(time(0));

    cout << "\nGenerated Random Numbers:\n";
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 1000;  // numbers between 0 and 999
        cout << arr[i] << " ";
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    cout << "\n\nSorted Numbers:\n";
    for (int num : arr)
        cout << num << " ";

    cout << "\n\nEnter number to search: ";
    cin >> target;

    // Measure time
    auto start = high_resolution_clock::now();
    int index = binarySearch(arr, target);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Output
    if (index != -1)
        cout << "\nElement found at index: " << index << endl;
    else
        cout << "\nElement not found in the array.\n";

    cout << "Time taken for Binary Search: " << duration.count() << " microseconds\n";

    return 0;
}
