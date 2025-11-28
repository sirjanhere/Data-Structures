#include <iostream>
using namespace std;

int main() {
    // Initialize the array with more elements
    int arr[] = {5, 2, 9, 1, 7, 8, 9, 10, 5, 12, 4, 6, 3, 11, 0};

    // Automatically calculate the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort Iterative Algorithm
    // Outer loop for each pass
    for(int i = 0; i < n-1; i++) {
        // Inner loop for comparing adjacent elements
        for(int j = 0; j < n-i-1; j++) {
            // Swap if the current element is greater than the next element
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        // After each pass, the largest element is bubbled to its correct position
    }

    // Print the sorted array
    cout << "Sorted array (Iterative Bubble Sort): ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
