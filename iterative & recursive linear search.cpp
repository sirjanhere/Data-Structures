#include <iostream>
using namespace std;

// Iterative Linear Search
int linearSearchIterative(int arr[], int n, int target) {
    // Loop through each element of the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is the target
        if (arr[i] == target) {
            return i; // Target found, return its index
        }
    }
    // Target not found in the array
    return -1;
}

// Recursive Linear Search
int linearSearchRecursive(int arr[], int n, int index, int target) {
    // Base case: if index reaches n, target not found
    if (index == n) {
        return -1;
    }

    // If current element is the target, return index
    if (arr[index] == target) {
        return index;
    }

    // Otherwise, continue searching in the rest of the array
    return linearSearchRecursive(arr, n, index + 1, target);
}

// Main Function
int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    // Iterative linear search
    int iterativeResult = linearSearchIterative(arr, n, target);
    if (iterativeResult != -1)
        cout << "Iterative: Element found at index " << iterativeResult << endl;
    else
        cout << "Iterative: Element not found" << endl;

    // Recursive linear search
    int recursiveResult = linearSearchRecursive(arr, n, 0, target); // start at index 0
    if (recursiveResult != -1)
        cout << "Recursive: Element found at index " << recursiveResult << endl;
    else
        cout << "Recursive: Element not found" << endl;

    return 0;
}
