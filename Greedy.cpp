#include<bits/stdc++.h>
using namespace std;
#define V 5
void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minind]){
                minind=j;
            }

        }
        swap(arr[i],arr[minind]);


    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int minkey(int key[],bool mstset[]){
    int min=INT_MAX,minind;
    for(int v=0;v<V;v++){
        if(!mstset[v] && key[v]<min){
            min=key[v];
            minind=v;
        }
    }
    return minind;
}
void print(int parent[],int graph[V][V]){
    cout<<"Edge\tWeight\t"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"- "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }

}
void prim(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstset[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int u=minkey(key,mstset);
        mstset[u]=true;
        for(int j=0;j<V;j++){
            if(graph[u][j]&& !mstset[j] && graph[u][j]<key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
            }
        }
    }
    print(parent,graph);


}
int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array:\n";
    display(arr, n);

    selectionsort(arr, n);

    cout << "\n\nSorted Array:\n";
    display(arr, n);
     int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    prim(graph);
}