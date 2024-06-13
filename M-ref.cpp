#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) : parent(size), rank(size, 0)
    {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int V, E;
        cin >> V >> E;
        map<string, int> studentIndex;
        UnionFind uf(V);
        int index = 0;

        for (int i = 0; i < E; ++i)
        {
            string studentA, studentB;
            cin >> studentA >> studentB;
            if (studentIndex.find(studentA) == studentIndex.end())
                studentIndex[studentA] = index++;
            if (studentIndex.find(studentB) == studentIndex.end())
                studentIndex[studentB] = index++;
            uf.unite(studentIndex[studentA], studentIndex[studentB]);
        }

        vector<bool> seen(V, false);
        int uniqueSets = 0;
        for (int i = 0; i < V; ++i)
        {
            int root = uf.find(i);
            if (!seen[root])
            {
                seen[root] = true;
                uniqueSets++;
            }
        }

        if (uniqueSets > 1)
            cout << "Menyirkel" << endl;
        else
            cout << "Tidak Menyirkel" << endl;
    }
    return 0;
}