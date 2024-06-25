#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;

    void init(long v)
    {
        vertexCount = v+1;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void bfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                {
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    void printGraph()
    {
        for (size_t i = 0; i < adjList.size(); ++i)
        {
            cout << "Vertex " << i << " is connected to: ";
            for (auto &edge : adjList[i])
            {
                cout << "(" << edge.first << ", " << edge.second << ") "; // Assuming edge.first is the connected vertex and edge.second is the weight
            }
            cout << endl;
        }
    }
};

int main()
{
    int kota, jembatan, start;
    cin >> kota >> jembatan >> start;

    queue<int> q;

    // Portal cost
    for(int i = 0; i < kota; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    graph g;
    g.init(kota);

    for (int i = 0; i < jembatan; i++){
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b, q.front());
        q.pop();
    }
    
    vector<long> bfs_result;

    g.findConnectedComponents();

    puts("");

    g.bfs(bfs_result, 5);

    for (auto it : bfs_result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}