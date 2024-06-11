#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int minRefillTime(vector<vector<pii>>& graph, int source, int k, int e) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int refillTime = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] != INT_MAX) {
            int potionsNeeded = (dist[i] + k - 1) / k;
            refillTime += potionsNeeded;
        }
    }

    refillTime -= e;
    return refillTime;
}

int main() {
    int n, m, k, e;
    cin >> n >> m >> k >> e;

    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        graph[a].push_back({b, p});
        graph[b].push_back({a, p});
    }

    int source;
    cin >> source;

    int refillTime = minRefillTime(graph, source, k, e);

    cout << "Waktu minimum refill yang efisien: " << refillTime << "\n";

    return 0;
}