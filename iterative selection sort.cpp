#include <iostream>
using namespace std;

int main() {
    // Initialize a larger array
    int arr[] = {5, 2, 9, 1, 7, 8, 9, 10, 5, 12, 4, 6, 3, 11, 0};

    // Automatically calculate the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Iterative Selection Sort Algorithm
    // Outer loop moves the boundary of unsorted subarray
    for(int i = 0; i < n-1; i++) {
        int minIndex = i; // Assume the first element of unsorted part is the minimum

        // Find the minimum element in the unsorted subarray
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if smaller element found
            }
        }

        // Swap the found minimum element with the first element of unsorted part
        swap(arr[i], arr[minIndex]);
        // Now the first i+1 elements are sorted
    }

    // Print the sorted array
    cout << "Sorted array (Iterative Selection Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
