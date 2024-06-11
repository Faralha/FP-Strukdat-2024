#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, vector<string>> topics;

void createTopic(const string &topic)
{
    topics[topic] = {};
}

void writeMessage(const string &topic, const string &message)
{
    topics[topic].push_back(message);
}

void readLastMessage(const string &topic)
{
    if (topics.find(topic) == topics.end() || topics[topic].empty())
    {
        cout << "Topic is empty" << endl;
    }
    else
    {
        cout << topics[topic].back() << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string operation;
        getline(cin, operation);

        if (operation.substr(0, 6) == "CREATE")
        {
            string topic = operation.substr(12);
            createTopic(topic);
        }
        else if (operation.substr(0, 5) == "WRITE")
        {
            size_t spacePos = operation.find(' ');
            string topic = operation.substr(6, spacePos - 6);
            string message = operation.substr(spacePos + 1);
            writeMessage(topic, message);
        }
        else if (operation.substr(0, 4) == "READ")
        {
            string topic = operation.substr(5);
            readLastMessage(topic);
        }
    }

    return 0;
}