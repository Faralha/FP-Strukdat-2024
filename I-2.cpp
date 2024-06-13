#include <bits/stdc++.h>
using namespace std;


int main()
{
    string input;
    cin >> input;

    stack<char> open;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '<' || input[i] == '[')
        {
            open.push(input[i]);
        }



        else if (!open.empty() && open.top() == '(' && input[i] == ')')
        {
            open.pop();
        }
        else if (!open.empty() && open.top() == '{' && input[i] == '}')
        {
            open.pop();
        }
        else if (!open.empty() && open.top() == '[' && input[i] == ']')
        {
            open.pop();
        }
        else if (!open.empty() && open.top() == '<' && input[i] == '>')
        {
            open.pop();
        }
        else
        {
            cout << "Belum ditutup" << endl;
            return 0;
        }
    }

    if (open.empty())
    {
        cout << "Sudah ditutup" << endl;
    }
    else
    {
        cout << "Belum ditutup" << endl;
    }

    return 0;
}