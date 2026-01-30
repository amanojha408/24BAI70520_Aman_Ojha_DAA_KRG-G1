#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjlist;
vector<int> path;
vector<bool> vis;
int V;

bool hasEdge(int u, int v) {
    for (int x : adjlist[u]) {
        if (x == v) return true;
    }
    return false;
}

bool solve(int u, int cnt) {
    if (cnt == V) {
        return hasEdge(u, path[0]);
    }

    for (int x : adjlist[u]) {
        if (!vis[x]) {
            vis[x] = true;
            path.push_back(x);

            if (solve(x, cnt + 1)) return true;

            vis[x] = false;
            path.pop_back();
        }
    }

    return false;
}

int main() {
    V = 5;

    adjlist = {
        {1, 3},
        {0, 2, 3, 4},
        {1, 4},
        {0, 1, 4},
        {1, 2, 3}
    };

    vis.assign(V, false);

    path.push_back(0);
    vis[0] = true;

    if (solve(0, 1)) {
        for (int node : path) cout << node << " ";
        cout << path[0] << endl;
    } 
    else {
        cout << "No Cycle Found" << endl;
    }

    return 0;
}
