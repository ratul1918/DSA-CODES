#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Find(int x, vector<int>& parent){
    if (parent[x] == -1) return x;
    return parent[x] = Find(parent[x], parent);
}

void UnionSets(int u, int v, vector<int>& parent, vector<int>& Rank){
    int RootU = Find(u, parent);
    int RootV = Find(v, parent);
    if (RootU == RootV) return;
    if (Rank[RootU] > Rank[RootV]) {
        parent[RootV] = RootU;
        Rank[RootU] += Rank[RootV];
    } else {
        parent[RootU] = RootV;
        Rank[RootV] += Rank[RootU];
    }
}

int main(){
    int V;
    cout << "Enter number of vertices: ";
    if (!(cin >> V)) return 0;

    vector<pair<int,int>> pts(V);
    cout << "Enter x y for each vertex (one per line):" << endl;
    for (int i = 0; i < V; ++i){
     cin >> pts[i].first >> pts[i].second;
    }
    // Build complete edge list with Manhattan distance
    vector<vector<int>> edges; // {w, u, v}
    for (int i = 0; i < V; ++i){
        for (int j = i+1; j < V; ++j){
            int w = abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
            edges.push_back({w, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(V, -1), Rank(V, 1);
    int mincost = 0, count = 0;
    for (auto &edge : edges){
        int w = edge[0], u = edge[1], v = edge[2];
        if (Find(u, parent) != Find(v, parent)){
            UnionSets(u, v, parent, Rank);
            mincost += w;
            cout << "Take edge: " << u << " - " << v << " (w=" << w << ")\n";
            if (++count == V-1) break;
        }
    }

    cout << "Minimum cost of spanning tree (Manhattan): " << mincost << endl;
    return 0;
}