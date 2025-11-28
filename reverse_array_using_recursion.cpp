#include <iostream>
#include <string>
using namespace std;

// Recursive function to reverse the array
template <typename T>
void reverseArray(T arr[], int start, int end) {
    if (start >= end) return; // base case

    // swap
    T temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // recursive call
    reverseArray(arr, start + 1, end - 1);
}

// Print function template
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // By default, use string (covers int, double, char too since input comes as text)
    string* arr = new string[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
