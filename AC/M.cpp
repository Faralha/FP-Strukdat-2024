#include <bits/stdc++.h>
using namespace std;

void circle()
{
    cout << "Menyirkel" << endl;
}

void notCircle()
{
    cout << "Tidak Menyirkel" << endl;
}

struct graph
{
    long vertexCount, edgeCount;
    map<string, vector<string>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;
    }

    void addEdge(string A, string B)
    {
        if(adjList.find(A) != adjList.end())
        {
            adjList[A].push_back(B);
    
            if(adjList.find(B) != adjList.end())
            {
                adjList[B].push_back(A);
            }
            else
            {
                adjList[B] = {A};
            }
        } else {
            adjList[A] = {B};
            if(adjList.find(B) != adjList.end())
            {
                adjList[B].push_back(A);
            }
            else
            {
                adjList[B] = {A};
            }
        }
    }

    // Conditions for "Menyirkel" :
    // 1. Edge is more than 1
    // 2. There's 1 member that's disconnected from the main edge

    void checkEr(){
        map<string, bool> visited;
        queue<string> queue;
        int edgeV2 = 0;

        string root = adjList.begin()->first;

        for (auto it = adjList.begin(); it != adjList.end(); ++it)
        {
            string root = it->first;
            if (visited[root] != true)
            {
                visited[root] = true;
                queue.push(root);

                while (!queue.empty())
                {
                    string current = queue.front();
                    queue.pop();

                    for (const auto &neighbor : adjList.at(current))
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            queue.push(neighbor);
                        }
                    }
                }
                edgeV2++;
            }
        }

        if (adjList.size() != vertexCount || edgeV2 > 1)
        {
            circle();
        }
        else
        {
            notCircle();
        }
    }

    bool isConnected()
    {
        if (adjList.empty())
            return false;

        map<string, bool> visited;
        int components = 0;

        for (const auto &pair : adjList)
        {
            if (!visited[pair.first])
            {
                bfs(visited, pair.first);
                components++;
            }
        }

        return components == 1 && (edgeCount == vertexCount - 1);
    }

    void bfs(map<string, bool> &visited, string start)
    {
        queue<string> queue;
        visited[start] = true;
        queue.push(start);

        while (!queue.empty())
        {
            string current = queue.front();
            queue.pop();

            for (const auto &neighbor : adjList[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {
        int V, E;
        cin >> V >> E;

        graph arekSirkel;
        arekSirkel.init(V);

        for (int i = 0; i < E; i++)
        {
            string A, B;
            cin >> A >> B;
            arekSirkel.addEdge(A, B);
        }

        arekSirkel.checkEr();

        // if (arekSirkel.isConnected())
        // {
        //     notCircle();
        // }
        // else
        // {
        //     circle();
        // }
        T--;
    }
}