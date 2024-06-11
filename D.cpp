#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<int, int> memo;

const int MOD = static_cast<int>(pow(10, 9) + 7);

int countCatalan(int N)
{
    if (N <= 1)
    {
        return 1;
    }

    if (memo.find(N) != memo.end())
    {
        return memo[N];
    }

    long long counts = 0;

    for (int i = 0; i < N; i++)
    {
        long long leftCount = 0;
        if (memo.find(i) != memo.end())
        {
            leftCount = memo[i];
        }
        else
        {
            leftCount = countCatalan(i);
            memo[i] = leftCount;
        }

        long long rightCount = 0;
        if (memo.find(N - i - 1) != memo.end())
        {
            rightCount = memo[N - i - 1];
        }
        else
        {
            rightCount = countCatalan(N - i - 1);
            memo[N - i - 1] = rightCount;
        }

        counts = (counts + (leftCount * rightCount) % MOD) % MOD;
    }

    memo[N] = counts;

    return counts;
}

int main()
{
    int N;
    cin >> N;

    int counts = countCatalan(N);
    cout << counts << endl;

    return 0;
}