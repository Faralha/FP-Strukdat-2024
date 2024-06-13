#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    const unsigned long long MOD = 1000000007;
    unsigned long long x = 1;
    for (int i = 2; i <= n; i++) {
        x = (x * i) % MOD;
    }
    return x;
}

int main() {
    unsigned long long N;
    cin >> N;

    cout << factorial(N) << endl;

    return 0;
}