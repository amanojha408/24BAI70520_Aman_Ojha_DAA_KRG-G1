
class Solution {
  public:
    vector<bool> vis;
    vector<int> path;
    
    bool solve(int u, int count, vector<vector<int>> adj, int n)
    {
        if(count == n - 1)
        {
            return true;
        }
        for(int i : adj[u])
        {
            if(!vis[i])
            {
                vis[i] = true;
                path.push_back(i);
                if(solve(i, count +1, adj, n)) return true;
                vis[i] = false;
                path.pop_back();
            }
        }
        return false;
    }
  
  
    bool check(int n, int m, vector<vector<int>> edges) {
        vector<vector<int>> adjList(n);
        for(auto i : edges)
        {
            adjList[i[0] - 1].push_back(i[1]-1);
            adjList[i[1] - 1].push_back(i[0]-1);
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            count = 0;
            vis = vector<bool> (n, false);
            path.push_back(i);
            vis[i] = true;
            if(solve(i, count, adjList, n))
            {
                return true;
            }
        }
        return false;
    }
};
