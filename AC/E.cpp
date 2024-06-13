#include <bits/stdc++.h>
using namespace std;

int bigger(int a, int b)
{
    return a > b ? a : b;
}

int lower(int a, int b)
{
    return a < b ? a : b;
}

void lookForRoot(int N, vector<int>& temp, vector<int>& temp2)
{
    if (N < 1)
    {
        return;
    }
    if (N % 2 != 0)
    {
        for (int i = 0; i < pow(2, N); i++)
        {
            if (i % 2 != 0)
            {
                temp2.push_back(bigger(temp[i], temp[i - 1]));
            }
        }
    } else if (N % 2 == 0){
        for (int i = 0; i < pow(2, N); i++)
        {
            if (i % 2 != 0)
            {
                temp2.push_back(lower(temp[i], temp[i - 1]));
            }
        }
    }
    temp = temp2;
    temp2.clear();
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> temp, temp2;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        temp.push_back(x);
    }

    int level = log2(N);
    // cout << "Log2: " << level << endl;

    while(level >= 1){
        lookForRoot(level, temp, temp2);
        level--;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}