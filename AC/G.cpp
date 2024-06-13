#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        adjList.resize(vertexCount);
    }

    void add_edge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    void bfs(vector<long> &result, long start, long cari)
    {
        vector<bool> visited(vertexCount, false);
        vector<long> search(vertexCount, -1);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);
        int found = 0;

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            if (temp == cari)
            {

                for (long i = cari; i != -1; i = search[i])
                {
                    // index buat vertex
                    // value buat parent
                    // cout << i << endl;
                    found++;
                }

                cout << found - 1 << endl;
                return;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true;
                    search[vertex] = temp;
                }
            }
        }
    }
};

int main()
{
    long pemain, operan, operanKali;

    cin >> pemain >> operan >> operanKali;

    graph g;
    g.init(pemain);

    while (operan > 0)
    {
        long a, b;
        cin >> a >> b;
        g.add_edge(a, b);
        operan--;
    }

    vector<long> bfs_result;

    while (operanKali > 0)
    {
        int a, b;
        cin >> a >> b;
        g.bfs(bfs_result, a, b);
        operanKali--;
    }

    return 0;
}