#include <iostream>
using namespace std;

// Recursive function to calculate sum of n elements
int sumArray(int arr[], int n) {
    if (n == 0)  // base case: no elements
        return 0;

    return arr[n - 1] + sumArray(arr, n - 1);  // add last element + sum of rest
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = sumArray(arr, n);
    cout << "Sum of the " << n << " elements is: " << total << endl;

    return 0;
}
