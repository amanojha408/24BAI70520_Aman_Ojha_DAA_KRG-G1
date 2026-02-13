#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> path;
vector<bool> vis;
int V;

bool hasEdge(int u, int v)
{
    for(int x : adjList[u])
    {
        if(x == v) return true;
    }
    return false;
}


bool solve(int u, int cnt)
{
    if(cnt == V)
    {
        return hasEdge(u, path[0]);
    }

    for(int v : adjList[u])
    {
        if(!vis[v])
        {
            vis[v] = true;
            path.push_back(v);
            if(solve(v, cnt + 1)) return true;
            
            vis[v] = false;
            path.pop_back();
        }

    }

    return false;
}



int main()
{

    V = 5;
    adjList = {
        {1, 3},
        {0,2,3,4},
        {1, 4},
        {0, 1,4},
        {1, 2, 3}
    };



    vis.assign(V, false);
    path.push_back(0);
    vis[0] = true; 
    if(solve(0, 1))
    {
        for(int i : path)
        {
            cout<<i<<" ";
        }
    }
    else{
        cout<<"No Path"<<endl;
    }
    return 0;
}
