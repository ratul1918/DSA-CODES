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
      void DFS(int start){
        vector<bool> visited(numVertices,false);
        stack<int> s;
        s.push(start);
        visited[start]=true;

        while(!s.empty()){
            int currentVertex=s.top();
            s.pop();
            cout<<currentVertex<<" ";
            for(int neighbor : adjList[currentVertex]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    s.push(neighbor);
                }
            }
        }
        
      }
};

int main(){
    int numVertices, numEdges,a,b;
    cout<<"Enter the number of vertices: ";
    cin>>numVertices;
    cout<<"Enter the num of edgees: ";
    cin>>numEdges;

    Graph graph(numVertices);

    for(int i=0;i<numEdges;i++){
        cout<<"enter endpoint of edge: ";
        cin>> a >> b;
        graph.addEdge(a,b);
    }

    cout<<"DFS starting from vertex 0: ";
    graph.DFS(0);

    cout <<endl;
}