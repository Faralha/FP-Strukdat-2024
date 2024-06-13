#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Modified Dijkstra's algorithm to include potion refill logic
int minRefillTime(vector<vector<pii>>& graph, int source, int k, int e) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Distance represents the minimum time including refills
    dist[source] = 0;
    vector<int> potions(n, k); // Track the number of potions left
    potions[source] = k; // Start with k potions

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
            int w = neighbor.second; // Potion usage

            int newDist = dist[u] + (potions[u] >= w ? 0 : (w - potions[u] + k - 1) / k * 3); // Calculate refill time
            int newPotions = max(0, potions[u] - w) % k; // Update potions left

            if (newDist < dist[v]) {
                dist[v] = newDist;
                potions[v] = newPotions;
                pq.push({dist[v], v});
            }
        }
    }

    // Check if the estimated time is less than the actual minimum time
    if (dist[n-1] > e) {
        cout << "muak gweh, butuh heal lagi" << endl;
    } else {
        return dist[n-1];
    }
}

int main() {
    int n, m, k, e;
    cin >> n >> m >> k >> e;
    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, p;
        cin >> a >> b >> p;
        --a; --b; // Adjusting for 0-based indexing
        graph[a].push_back({b, p});
        graph[b].push_back({a, p}); // Assuming undirected graph for bidirectional movement
    }

    int result = minRefillTime(graph, 0, k, e);
    if (result != -1) {
        cout << result << endl;
    }

    return 0;
}