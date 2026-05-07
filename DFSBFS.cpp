#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    vector<vector<int>> adj;
    int vertices;

    public:

    Graph(int v){
        vertices = v;
        adj.resize(v);
    }

    void addedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start, vector<bool> &visited){
        visited[start] = true;
        cout<<start<<" ";
        for(auto it : adj[start]){
            if(!visited[it]){
                DFS(it,visited);
            }
        }
    }

    void BFS(int start){
        vector<bool> visited(vertices,false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout<<vertex<<" ";
            for(auto it : adj[vertex]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
    }

};


int main(){
    int v,e;
    cout<<"Enter number of vertices\n";
    cin>>v;
    Graph g(v);
    cout<<"\nEnter number of edges\n";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int x,y;
        cout<<"\nEnter edge : "<<i+1<<"\n";
        cin>>x>>y;
        g.addedge(x,y);
    }
    int start;
    vector<bool> visited(v,false);
    cout<<"\nEnter starting vertex :\n";
    cin>>start;
    cout<<"DFS : \n";
    g.DFS(start,visited);
    cout<<"\nBFS : \n";
    g.BFS(start);

}