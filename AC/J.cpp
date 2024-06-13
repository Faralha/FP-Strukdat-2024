#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    map<string, vector<string>> topics;
    stack<string> topicStack;

    for (int i = 0; i < T; i++)
    {
        string command;
        cin >> command;

        if (command == "CREATE")
        {
            string topic, dummy;
            cin >> dummy >> topic;
            topicStack.push(topic);
        }

        else if (command == "WRITE")
        {
            string topic, content;
            cin >> topic >> content;
            topics[topic].push_back(content);
        }

        else if (command == "READ")
        {
            string topic, dummy;
            cin >> dummy >> topic;

            if (topics.find(topic) != topics.end() && !topics[topic].empty())
            {
                if (!topics[topic].empty())
                {
                    cout << topics[topic].back() << endl;
                    topics[topic].pop_back();
                }
                else
                {
                    cout << "Topic is empty" << endl;
                }
            }
            else
            {
                cout << "Topic is empty" << endl;
            }
        }
    }
}