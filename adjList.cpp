#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > adjList;
public:
    Graph(int v) {
        this->V = v;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjList[u].push_back(v);
            adjList[v].push_back(u); // For undirected graph
        }
        else {
            cout << "Out of boundary!" << endl;
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph adjacency list:" << endl;
    g.printGraph();

    return 0;
}
