// Recursive function to find the maximum elements in an array

#include <iostream>
#include <vector>
#include <limits>   // For numeric limits
#include <sstream>  // For stringstream conversion
using namespace std;

// Recursive function to find the maximum element in the vector
double find_max_recursive(const vector<double> &arr, int n) {
    // Base case: if only one element, return it
    if (n == 1) {
        return arr[0];
    }
    // Recursive case: get the maximum of the first n-1 elements
    double max_in_rest = find_max_recursive(arr, n - 1);
    // Compare last element and max of rest, return the larger
    return (arr[n-1] > max_in_rest) ? arr[n-1] : max_in_rest;
}

int main() {
    vector<double> numbers;   // Vector to store user inputs (integers/floats)
    string input;             // String for input handling

    cout << "Enter numbers (int or float), one per line.\n";
    cout << "Type 'end' (without quotes) to finish input.\n";

    // Reading numbers from user until 'end' is typed
    while (true) {
        cout << "Enter element: ";
        getline(cin, input);  // Read input as string
        if (input == "end") { // Exit loop when 'end' is entered
            break;
        }
        double value;
        stringstream ss(input);
        if (ss >> value && ss.eof()) {
            numbers.push_back(value); // Save successfully parsed number
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }

    if (numbers.empty()) {
        cout << "No elements to process.\n";
        return 0; // Exit if no input was given
    }

    // Call the recursive function with the full array
    double maximum = find_max_recursive(numbers, numbers.size());
    cout << "The maximum element is: " << maximum << "\n";
    return 0;
}
