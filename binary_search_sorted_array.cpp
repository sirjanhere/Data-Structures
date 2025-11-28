// Recursive function to perform binary search on a sorted array

#include <iostream>
using namespace std;

// Recursive binary search using template (works with double for mixed int/float)
template<typename T>
int binarySearch(T arr[], int left, int right, T key) {
    if (left > right)
        return -1;
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, left, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Create dynamic array of doubles to store user input
    double* arr = new double[n];

    cout << "Enter " << n << " elements (integers/floats, sorted in ascending order, one in each line):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];  // Save each element in the array
    }

    double key;
    cout << "Enter key to search (integer or float): ";
    cin >> key;

    // Perform recursive binary search
    int index = binarySearch<double>(arr, 0, n - 1, key);

    if (index != -1)
        cout << "Element found at index (0-based): " << index << endl;
    else
        cout << "Element not found!" << endl;

    // Display the array contents (to verify elements were saved)
    cout << "\nArray contents: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // Free memory
    return 0;
}
