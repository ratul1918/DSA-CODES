#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges; // Input total number of nodes and edges..

    // Create an adjacency list for the graph (1-indexed)..
    vector<vector<int> > adjacencyList(numNodes + 1);

    // Read edges and populate the adjacency list
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to; // Input each edge (undirected)
        adjacencyList[from].push_back(to); // Add 'to' to 'from's list
        adjacencyList[to].push_back(from); // Add 'from' to 'to's list
    }

    int startNode, endNode;
    cin >> startNode >> endNode; // Input the start and end nodes to find the shortest path between

    // Initialize distances from the start node to all other nodes as -1 (meaning unvisited)
    vector<int> distance(numNodes + 1, -1);

    // Queue for BFS traversal
    queue<int> bfsQueue;

    // Set the distance to the start node as 0 and enqueue it
    distance[startNode] = 0;
    bfsQueue.push(startNode);

    // Start BFS loop
    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front(); // Get the front node in the queue
        bfsQueue.pop(); // Remove it from the queue

        // Visit all adjacent (neighbor) nodes
        for (int neighbor : adjacencyList[currentNode]) {
            if (distance[neighbor] == -1) { // If not visited yet
                distance[neighbor] = distance[currentNode] + 1; // Update distance
                bfsQueue.push(neighbor); // Enqueue the neighbor for further exploration
            }
        }
    }

    // If endNode was never reached (distance still -1), graph is disconnected
    if (distance[endNode] == -1)
        cout << "DISCONNECTED" << endl;
    else
        cout << distance[endNode] << endl; // Output shortest path length (number of edges)

    return 0; // Exit program
}
