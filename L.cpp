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
        
        for(long i = 0; i < vertexCount; i++)
            adjList.push_back({});
    }

    void addEdge(long A, long B)
    {
        adjList[A].push_back(B);
        adjList[B].push_back(A);
        edgeCount++;

        // cout << A << " " << B << " ADDED\n";
    }

    void prlongGraph()
    {
        for (long i = 1; i < vertexCount; i++)
        {
            // cout << "Adjacent vertices of vertex " << i << ": ";
            for (long j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(long search, vector<long>& result)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        // cout << "START DATATYPE: " << typeid(search).name() << endl;
        visited[search] = true;
        q.push(search);
        result.push_back(search);

        while (!q.empty())
        {
            long current = q.front();
            q.pop();

            // for(long i = 0; i < adjList[current].size(); i++){
            //     long vertex = adjList[current][i];
            //     if(!visited[vertex]){
            //         cout << vertex << " ";
            //         visited[vertex] = true;
            //         q.push(vertex);
            //         result.push_back(vertex);
            //     }
            // }

            for (long i = 0; i < adjList[current].size(); i++)
            {
                long next = adjList[current][i];
                if (!visited[next])
                {
                    // cout << next << " ";
                    visited[next] = true;
                    q.push(next);
                    result.push_back(next);
                }
            }
        }
    }
};

long cheapestPath(vector<long> kota, vector<long> price){
    long min = LONG_MAX;
    for(long i = 0; i < kota.size(); i++){
        // cout << "PRICE FOR " << kota[i] << " : " << price[kota[i]-1] << endl;
        if(price[kota[i]-1] < min)
            min = price[kota[i]-1];
    }

    return min;
}

bool checkSameMembers(const vector<long> &result, const vector<long> &result2)
{
    vector<long> sortedResult(result.begin(), result.end());
    vector<long> sortedResult2(result2.begin(), result2.end());
    sort(sortedResult.begin(), sortedResult.end());
    sort(sortedResult2.begin(), sortedResult2.end());

    if (sortedResult[0] == sortedResult2[0])
    {
        return true;
    }
    return false;
}

int main()
{
    long kota, jembatan, kotaAwal;
    long sumPrice = 0;

    cin >> kota >> jembatan >> kotaAwal;

    vector<long> price;
    for (long i = 0; i < kota; i++)
    {
        long a;
        cin >> a;
        price.push_back(a);
    }



    // for(auto i : price)
    //     cout << i << " ";



    graph g;
    g.init(jembatan+2);


    for (long i = 0; i < jembatan; i++)
    {
        long a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }

    // g.prlongGraph();

    long lastKota = kotaAwal;

    // cout << "PHASE 2" << endl;

    long T;
    cin >> T;
    while (T--)
    {
        long a, b, c;
        cin >> a;

        if (a == 1)
        {
            // Biaya portal kota K berubah jadi X
            cin >> b >> c;
            price[b-1] = c;
            // cout << "PRICE UPDATED FOR " << b << " TO " << c << endl;
        }


        else if (a == 2)
        {
            // cout << "TRAVELING" << endl;
            // Indra ingin pergi ke kota K dari kota terakhir yang dia kunjungi.
            cin >> b;

            long oldPrice = 0;
            long newPrice = 0;

            // cout << "LAST CITY: " << kotaStack.top() << ", NEW CITY: " << b << endl;

            long kotaOld = lastKota;
            // cout << kotaOld << " " << endl;
            lastKota = b;
            long kotaNew = lastKota;

            vector<long> result, result2;
            g.bfs(kotaOld, result);
            g.bfs(kotaNew, result2);

            if(checkSameMembers(result, result2)){
                oldPrice = 0;
                newPrice = 0;
            } else {
                oldPrice = cheapestPath(result, price);
                newPrice = cheapestPath(result2, price);
            }


            // cout << "BFS FOR " << kotaOld << " : ";
            // for(auto i : result)
            //     cout << i << " ";
            // puts("");

            // cout << "BFS FOR " << kotaNew << " : ";
            // for (auto i : result2)
            //     cout << i << " ";
            // puts("");


        
            sumPrice += (newPrice + oldPrice); 

            // cout << "TRAVEL " << kotaOld << " TO " << kotaNew << " : " << newPrice << " + " << oldPrice << endl;
        }
    }

    cout << sumPrice << endl;

    // for (auto i : price)
    //     cout << i << " ";

    return 0;
}