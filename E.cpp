#include <bits/stdc++.h>
using namespace std;

int countLevel(int N)
{
    if (N <= 1)
    {
        return 1;
    }
    N = N / 2;
    return 1 + countLevel(N);
}

int main()
{
    int N;
    cin >> N;
    
    // gausah pake count level, harusnya bisa langsung
    int level = countLevel(N);

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // if odd, give max value
    for (int i = level - 1; i >= 0; i--)
    {

        if (i % 2 != 0)
        {
            int temp = 0;
            // MAX
            for (int j = 0; j < N; j += 2)
            {
                if (arr[j] > arr[j + 1])
                {
                    arr[temp] = arr[j];
                }
                else
                {
                    arr[temp] = arr[j + 1];
                }
                N /= 2;
                temp++;
            }
        }

        else
        {
            int temp = 0;
            // MIN
            for (int j = 0; j < N; j += 2)
            {
                if (arr[j] < arr[j + 1])
                {
                    arr[temp] = arr[j];
                }
                else
                {
                    arr[temp] = arr[j + 1];
                }
                N /= 2;
                temp++;
            }
        }

    }

    cout << arr[0] << endl;
    return 0;
}