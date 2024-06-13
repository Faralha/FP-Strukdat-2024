#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    map<string, vector<string>> adjList;

    void init(long V)
    {
        vertexCount = V;
        edgeCount = 0;
    }

    int edges(){
        return edgeCount;
    }

    void addEdge(string A, string B)
    {
        if (find(adjList[A].begin(), adjList[A].end(), B) == adjList[A].end())
        {
            adjList[A].push_back(B);
            edgeCount++;
        }

        if (find(adjList[B].begin(), adjList[B].end(), A) == adjList[B].end())
        {
            adjList[B].push_back(A);
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

        graph arekSirkel;
        arekSirkel.init(V);

        while (E--)
        {
            string A, B;
            cin >> A >> B;

            arekSirkel.addEdge(A, B);

            

            // cout << arekSirkel.findConnected(A, B) << endl;
        }

        int edging = arekSirkel.edges();
        if(V - edging > 1){
            cout << "Menyirkel" << endl;
        } else {
            cout << "Tidak Menyirkel" << endl;
        }
    }
}