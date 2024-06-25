#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    unordered_map<long, vector<long>> bfsCache;

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


        visited[search] = true;
        q.push(search);
        result.push_back(search);

        while (!q.empty())
        {
            long current = q.front();
            q.pop();


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

    void cachedBfs(long search, vector<long>& result)
    {
        if(bfsCache.find(search) != bfsCache.end()){
            result = bfsCache[search];
            return;
        }

        bfs(search, result);
        bfsCache[search] = result;
    }

    
};

long cheapestPath(vector<long> kota, vector<long> price){
    long min = LONG_MAX;
    for(long i = 0; i < kota.size(); i++){

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






    graph g;
    g.init(jembatan+2);


    for (long i = 0; i < jembatan; i++)
    {
        long a, b;
        cin >> a >> b;

        g.addEdge(a, b);
    }


    long lastKota = kotaAwal;


    long T;
    cin >> T;
    while (T--)
    {
        long a, b, c;
        cin >> a;

        if (a == 1)
        {
  
            cin >> b >> c;
            price[b-1] = c;

        }


        else if (a == 2)
        {

            // Indra ingin pergi ke kota K dari kota terakhir yang dia kunjungi.
            cin >> b;

            long oldPrice = 0;
            long newPrice = 0;



            long kotaOld = lastKota;

            lastKota = b;
            long kotaNew = lastKota;

            vector<long> result, result2;
            g.cachedBfs(kotaOld, result);
            g.cachedBfs(kotaNew, result2);

            if(checkSameMembers(result, result2)){
                oldPrice = 0;
                newPrice = 0;
            } else {
                oldPrice = cheapestPath(result, price);
                newPrice = cheapestPath(result2, price);
            }




        
            sumPrice += (newPrice + oldPrice); 

        }
    }

    cout << sumPrice << endl;



    return 0;
}