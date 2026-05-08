#include<bits/stdc++.h>
using namespace std;
#define V 4
bool issafe(int graph[V][V],int color[],int v,int c){
    for(int i=0;i<V;i++){
        if(graph[v][i]&& color[i]==c)
            return false;
    }
    return true;
}
bool graphutil(int graph[V][V],int m,int color[],int v){
    if(v==V) return true;
    for(int c=1;c<=m;c++){
        if(issafe(graph,color,v,c)){
            color[v]=c;
            if(graphutil(graph,m,color,v+1))
                return true;
            color[v]=0;
        }
    }
    return false;
}

bool coloring(int graph[V][V],int m){
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=0;
    }
    if(!graphutil(graph,m,color,0)){
        cout<<"No solution"<<endl;
        return false;
    }
    for(int i=0;i<V;i++){
        cout<<"Vertex"<<i<<"-->>"<<color[i]<<endl;

    }
    return true;
}

int main(){
       int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    int m = 3;
    coloring(graph,m);
    return 0;
}