#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
 int numVertices;
 vector<vector<int> > adjList;

 public:
      Graph(int v){
        numVertices =v;
        adjList.resize(v);
      }

      void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
      void BFS(int start){
        vector<bool> visited(numVertices,false);
        queue<int> q;

        visited[start]=true;
        q.push(start);

        while(!q.empty()){
            int currentVertex=q.front();
            q.pop();
            cout<<currentVertex<<" ";

            for(int neighbor : adjList[currentVertex]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
      }
};

int main()
{
    int numVertices, numEdges,a,b;
    cout<<"Enter the number of vertices: ";
    cin>>numVertices;
    cout<<"Enter the num of edgees: ";
    cin>>numEdges;

    Graph graph(numVertices);

    for(int i=0;i<=numEdges;i++){
        cout<<"enter endpoint of edge: ";
        cin>> a >> b;
        graph.addEdge(a,b);
    }

    cout<<"BFS starting from vertex 0: ";
    graph.BFS(0);

    cout <<endl;
}
