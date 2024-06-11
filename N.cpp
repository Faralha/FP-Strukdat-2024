#include <bits/stdc++.h>
using namespace std;

void printMain(string region, string trailblazer, int power, string element)
{
    cout << "*****************************************************************************" << endl;
    cout << "Honkai Star Trail Region " << region << endl;
    cout << "Trailblazer : " << trailblazer << endl;
    cout << "Element : " << element << " - " << power << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

int power(int rawPower){
    if(rawPower % 2 == 0){
        return (rawPower * 108 / 100);
    } else {
        return (rawPower * 115 / 100);
    }
}


int main()
{
    string trailblazer, element, region;
    int n, x;
    int monster[n][2];

    cin >> trailblazer >> n >> element >> x >> region;
    for (int i = 0; i < n;i++){
        int a, b;
        cin >> a >> b;
        monster[i][0] = a;
        monster[i][1] = b;
    }
}