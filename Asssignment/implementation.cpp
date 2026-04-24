#include <bits/stdc++.h>
using namespace std;

#define V 5

bool isSafe(int v, bool graph[V][V], vector<int>& path, int pos) {
    // Check if current vertex is adjacent to previous
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if already visited
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(bool graph[V][V], vector<int>& path, int pos) {
    // If all vertices are included
    if (pos == V) {
        // Check if last vertex connects to first
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    // Try different vertices
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur for next position
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }
    return false;
}

void hamCycle(bool graph[V][V]) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists\n";
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    bool graph[V][V] = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    hamCycle(graph);
}

/*
TIME COMPLEXITY:
- Worst case: O(V!)
  Reason: We try all permutations of vertices to form a cycle.

- isSafe() takes O(V) time (checking visited vertices)

- So total complexity: O(V * V!) ≈ O(V!)

SPACE COMPLEXITY:
- O(V) for path array
- O(V) recursion stack depth

Overall auxiliary space: O(V)
*/
