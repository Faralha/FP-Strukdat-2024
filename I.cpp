#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    stack <int>open;

    int closed = 0;

    for (int i = 0; i < input.length(); i++)
    {
        // if()
        if (input[i] == '(')
        {
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[j] == ')')
                {
                    input[j] = '.';
                    closed++;
                    break;
                }
            }
        }
        if (input[i] == '{')
        {
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[j] == '}')
                {
                    input[j] = '.';
                    closed++;
                    break;
                }
            }
        }
        if (input[i] == '<')
        {
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[j] == '>')
                {
                    input[j] = '.';
                    closed++;
                    break;
                }
            }
        }
        if (input[i] == '[')
        {
            for (int j = i + 1; j < input.length(); j++)
            {
                if (input[j] == ']')
                {
                    input[j] = '.';
                    closed++;
                    break;
                }
            }
        }
    }

    cout << input << endl;

    if (closed * 2 == input.length())
    {
        cout << "Sudah ditutup";
    }
    else
    {
        cout << "Belum ditutup";
    }
    return 0;
}