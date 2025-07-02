#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertex, edges;
    cin >> vertex >> edges; // Input number of vertices and edges

    // Initialize a vertex x vertex matrix with all 0s
    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> weight; // Input each edge: u, v, and its weight
        adjMat[u][v] = weight;   // Set weight from u to v
        adjMat[v][u] = weight;   // Set weight from v to u (undirected)
    }

    // Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
