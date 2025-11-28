#include <iostream>
using namespace std;

// Function to find index of minimum element in arr[start..end]
int findMinIndex(int arr[], int start, int end) {
    // Base case: only one element
    if(start == end) return start;

    // Recursively find minimum in rest of the array
    int minIndexRest = findMinIndex(arr, start + 1, end);

    // Return the index of smaller element between start and the rest
    return (arr[start] < arr[minIndexRest]) ? start : minIndexRest;
}

// Recursive Selection Sort function
void selectionSortRecursive(int arr[], int n, int index = 0) {
    // Base case: If entire array is sorted
    if(index == n) return;

    // Find index of minimum element in unsorted array
    int minIndex = findMinIndex(arr, index, n-1);

    // Swap minimum element with first element of unsorted part
    swap(arr[index], arr[minIndex]);

    // Recursively sort remaining array
    selectionSortRecursive(arr, n, index + 1);
}

int main() {
    // Initialize a larger array
    int arr[] = {5, 2, 9, 1, 7, 8, 9, 10, 5, 12, 4, 6, 3, 11, 0};

    // Automatically calculate the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call recursive selection sort
    selectionSortRecursive(arr, n);

    // Print the sorted array
    cout << "Sorted array (Recursive Selection Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
