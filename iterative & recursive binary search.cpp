#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0;          // Start index of the array
    int right = n - 1;     // End index of the array

    while (left <= right) {
        // Find the middle index to split the array
        int mid = left + (right - left) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; // Target found, return index
        }
        // If target is smaller than mid element, ignore right half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger than mid element, ignore left half
        else {
            left = mid + 1;
        }
    }

    // Target not found in array
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    // Base case: if left index exceeds right, target is not found
    if (left > right) {
        return -1;
    }

    // Find the middle index
    int mid = left + (right - left) / 2;

    // Check if middle element is the target
    if (arr[mid] == target) {
        return mid; // Target found
    }
    // If target is smaller, search in left subarray
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    // If target is larger, search in right subarray
    else {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

// Main Function
int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    // Iterative search
    int iterativeResult = binarySearchIterative(arr, n, target);
    if (iterativeResult != -1)
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    else
        cout << "Iterative: Element not found" << endl;

    // Recursive search
    int recursiveResult = binarySearchRecursive(arr, 0, n - 1, target);
    if (recursiveResult != -1)
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    else
        cout << "Recursive: Element not found" << endl;

    return 0;
}
