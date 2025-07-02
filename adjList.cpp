#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges; // Input number of vertices and edges

    vector<int> adList[100]; // Adjacency list (array of vectors)

    int u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;              // Input one edge
        adList[u].push_back(v);     // Add edge u -> v
        adList[v].push_back(u);     // Add edge v -> u (undirected)
    }

    // Print adjacency list
    for (int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adList[i].size(); j++) {
            cout << adList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
