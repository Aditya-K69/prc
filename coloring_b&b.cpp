#include <bits/stdc++.h>
using namespace std;

#define V 4

int bestColors = V;          // Upper bound
int bestAssignment[V];

bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

void branchAndBound(int graph[V][V],
                    int color[],
                    int v,
                    int usedColors) {

    // ----- BOUND -----
    // Prune if already worse than best solution
    if (usedColors >= bestColors)
        return;

    // All vertices colored
    if (v == V) {
        bestColors = usedColors;

        for (int i = 0; i < V; i++)
            bestAssignment[i] = color[i];

        return;
    }

    // Try assigning existing colors first
    for (int c = 1; c <= usedColors + 1; c++) {

        if (isSafe(graph, color, v, c)) {

            color[v] = c;

            // If new color introduced
            int newUsedColors = max(usedColors, c);

            branchAndBound(graph,
                           color,
                           v + 1,
                           newUsedColors);

            // Backtrack
            color[v] = 0;
        }
    }
}

int main() {

    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int color[V] = {0};

    branchAndBound(graph, color, 0, 0);

    cout << "Minimum colors needed: "
         << bestColors << endl;

    cout << "Color Assignment:\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex "
             << i
             << " --> Color "
             << bestAssignment[i]
             << endl;
    }

    return 0;
}