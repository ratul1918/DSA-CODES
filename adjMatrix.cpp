#include <iostream
using namespace std;

#define MAX_V 4

class Graph {
private:
    int V;
    int adjMat[MAX_V][MAX_V];
public:
    Graph(int v) {
        this->V = v;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjMat[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        if(u >= 0 && u < V && v >= 0 && v < V) {
            adjMat[u][v] = 1;
            adjMat[v][u] = 1; // For undirected graph..
        }
        else {
            cout << "Out of boundary!" << endl;
        }
    }

    void removeEdge(int u, int v) {
        if(u >= 0 && u < V && v >= 0 && v < V) {
            adjMat[u][v] = 0;
            adjMat[v][u] = 0; // For undirected graph..
        }
        else {
            cout << "Out of boundary!" << endl;
        }
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(MAX_V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    
    cout << "Graph adjacency matrix:" << endl;
    g.printGraph();
    
    g.removeEdge(1, 2);
    
    cout << "Graph after removing edge (1, 2):" << endl;
    g.printGraph();
    
    return 0;
}
