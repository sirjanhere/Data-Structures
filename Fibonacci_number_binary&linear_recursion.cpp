#include <iostream>
#include <vector>
using namespace std;

// -------------------- Binary Recursion with Memoization --------------------
long long fibonacciBinaryMemo(int n, vector<long long>& memo) {
    if (n == 0) return 0;   // base case
    if (n == 1) return 1;   // base case

    if (memo[n] != -1) return memo[n];   // already computed

    memo[n] = fibonacciBinaryMemo(n - 1, memo) + fibonacciBinaryMemo(n
    - 2, memo);
    return memo[n];
}

// -------------------- Linear Recursion --------------------
long long fibonacciLinearHelper(int n, long long a, long long b) {
    if (n == 0) return a;
    return fibonacciLinearHelper(n - 1, b, a + b);
}

long long fibonacciLinear(int n) {
    return fibonacciLinearHelper(n, 0, 1);
}

int main() {
    int n;
    cout << "Enter n (nth Fibonacci number): ";
    cin >> n;

    // Memoization vector for binary recursion (-1 = not computed)
    vector<long long> memo(n + 1, -1);

    cout << "\nUsing Binary Recursion with Memoization: " <<
    fibonacciBinaryMemo(n, memo) << endl;
    cout << "Using Linear Recursion: " << fibonacciLinear(n) << endl;

    return 0;
}
