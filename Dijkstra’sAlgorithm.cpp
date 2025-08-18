// Problem: Find shortest paths from source node to all other nodes in a weighted graph (Dijkstra's Algorithm).
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int V, vector<pair<int,int>> adj[], int src) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; ++i)
        cout << "Distance to " << i << ": " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<pair<int,int>> adj[5];

    // u -> (v, weight).
    adj[0].push_back({1, 10});
    adj[0].push_back({4, 5});
    adj[1].push_back({2, 1});
    adj[2].push_back({3, 4});
    adj[4].push_back({1, 3});
    adj[4].push_back({2, 9});
    adj[4].push_back({3, 2});

    dijkstra(V, adj, 0);
    return 0;
}
