// Recursive function to print elements of an array in reverse order

#include <iostream>
#include <string>
using namespace std;

template<typename T>
void printReverse(T arr[], int n) {
    if (n == 0)
        return;
    cout << arr[n - 1] << " ";
    printReverse(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cin.ignore();

    string* arr = new string[n];

    cout << "Enter elements (int, float, char, string, or any mix)(one element in each line):\n";
    for (int i = 0; i < n; ++i) {
        getline(cin, arr[i]);
    }

    cout << "Elements in reverse order:\n";
    printReverse<std::string>(arr, n);

    delete[] arr;
    cout << endl;
    return 0;
}

