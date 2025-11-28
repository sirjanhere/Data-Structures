#include <iostream>
using namespace std;

// Recursive function to perform bubble sort
void bubbleSortRecursive(int arr[], int n) {
    // Base case: if array has only 1 element, it's already sorted
    if(n == 1) return;

    // One pass of bubble sort: move the largest element to the end
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    // Recursive call for the remaining array (excluding the last element)
    bubbleSortRecursive(arr, n-1);
}

int main() {
    // Initialize the array with more elements
    int arr[] = {5, 2, 9, 1, 7, 8, 9, 10, 5, 12, 4, 6, 3, 11, 0};

    // Automatically calculate the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call recursive bubble sort
    bubbleSortRecursive(arr, n);

    // Print the sorted array
    cout << "Sorted array (Recursive Bubble Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
