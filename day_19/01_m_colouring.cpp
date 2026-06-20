#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        // Check if adjacent node has the same color
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if (node == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0;  // Backtrack if the color assignment does not lead to a solution
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = { 0 };
    if (solve(0, color, m, N, graph)) return true;
    return false;
}

int main() {
    int nodes = 4;
    int colors = 3;  // Maximum number of colors

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Create a sample graph with edges (0,1), (1,2), (2,3), (3,0), (0,2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    // Output if the graph can be colored with at most m colors
    cout << graphColoring(graph, colors, nodes);

    return 0;
}