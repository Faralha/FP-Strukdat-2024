#include <iostream>
using namespace std;

// Function to calculate factorial
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the number of heap-ordered binary tree configurations
unsigned long long heapOrderedTrees(int n) {
    unsigned long long twoNFact = factorial(2 * n);
    unsigned long long nFact = factorial(n);
    unsigned long long nPlusOneFact = factorial(n + 1);

    return twoNFact / (nPlusOneFact);
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Number of heap-ordered binary tree configurations: " << heapOrderedTrees(n) << endl;

    return 0;
}