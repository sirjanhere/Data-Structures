#include <iostream>
using namespace std;

void insertionSortRecursive(int arr[], int n) {
    // Base case: 1 element is already sorted
    if(n <= 1) return;

    // Sort first n-1 elements recursively
    insertionSortRecursive(arr, n-1);

    // Insert nth element into sorted portion
    int last = arr[n-1];
    int j = n-2;
    while(j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

int main() {
    int arr[] = {5, 2, 9, 1, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSortRecursive(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
