#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        edgeCount++;
    }

    void dfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                result.push_back(temp);
                visited[temp] = true;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
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
};

int main()
{
    int N, M, K, E;
    cin >> N >> M >> K >> E;

    graph g;
    g.init(M);

    for (int i = 0; i < N;i++){
        int a, b, p;
        cin >> a >> b >> p;

        g.add_edge(a, b, p);
    }

    vector<long> dfs_result, bfs_result;
    g.dfs(dfs_result, 4);

    for (auto it : dfs_result)
    {
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs_result, 4);

    for (auto it : bfs_result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}