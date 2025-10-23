#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int from, to, time;
};

int main() {
    int n, m;
    cout << "Enter number of star systems and wormholes: ";
    cin >> n >> m;
    vector<Edge> edges(m);
    cout << "Enter each wormhole as from to time difference\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].time;
    }

    vector<int> dist(n, 0);
    bool hasNegativeCycle = false;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.to] > dist[e.from] + e.time) {
                dist[e.to] = dist[e.from] + e.time;
            }
        }
    }

    for (const auto& e : edges) {
        if (dist[e.to] > dist[e.from] + e.time) {
            hasNegativeCycle = true;
            break;
        }
    }

    cout << "Result: ";
    cout << (hasNegativeCycle ? "possible" : "not possible") << endl;
    return 0;
}
