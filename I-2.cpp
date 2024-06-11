#include <bits/stdc++.h>
using namespace std;

void tutup()
{
    cout << "Sudah ditutup";
}

void buka()
{
    cout << "Belum ditutup";
}

int main()
{
    string input;
    getline(cin, input);

    stack<char> open;

    if (input.length() % 2 != 0)
    {
        buka();
        return 0;
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (input.length() % 2 != 0)
        {
            buka();
            return 0;
        }
        if (input[i] == '(' || input[i] == '{' || input[i] == '<' || input[i] == '[')
        {
            open.push(input[i]);
        }
        else

            if (!open.empty() && open.top() == '(' && input[i] == ')')
        {
            open.pop();
        }
        else

            if (!open.empty() && open.top() == '{' && input[i] == '}')
        {
            open.pop();
        }
        else

            if (!open.empty() && open.top() == '[' && input[i] == ']')
        {
            open.pop();
        }
        else

            if (!open.empty() && open.top() == '<' && input[i] == '>')
        {
            open.pop();
        }
        else
        {
            buka();
            return 0;
        }
    }

    if (open.empty())
    {
        tutup();
    }
    else
    {
        buka();
    }

    return 0;
}