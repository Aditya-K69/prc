#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100];
bool visited[100];

// ---------- DFS ----------
void DFS(int node, int searchNode)
{
    visited[node] = true;

    cout << node << " ";

    if(node == searchNode)
    {
        cout << "\nNode Found using DFS!\n";
    }

    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            DFS(neighbor, searchNode);
        }
    }
}

// ---------- BFS ----------
void BFS(int start, int searchNode, int V)
{
    bool bfsVisited[100] = {false};

    queue<int> q;

    q.push(start);
    bfsVisited[start] = true;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        if(node == searchNode)
        {
            cout << "\nNode Found using BFS!\n";
        }

        for(int neighbor : graph[node])
        {
            if(!bfsVisited[neighbor])
            {
                bfsVisited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// ---------- MAIN ----------
int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";

    // Input edges
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    int startNode, searchNode;

    cout << "Enter starting node: ";
    cin >> startNode;

    cout << "Enter node to search: ";
    cin >> searchNode;

    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. DFS\n";
        cout << "2. BFS\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                // Reset visited array
                for(int i = 0; i < V; i++)
                {
                    visited[i] = false;
                }

                cout << "\nDFS Traversal:\n";

                DFS(startNode, searchNode);

                cout << endl;

                break;

            case 2:

                cout << "\nBFS Traversal:\n";

                BFS(startNode, searchNode, V);

                cout << endl;

                break;

            case 3:

                cout << "Exiting Program...\n";
                break;

            default:

                cout << "Invalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}