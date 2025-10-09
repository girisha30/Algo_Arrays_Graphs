#include <iostream>
#include <vector>
using namespace std;

bool backtrack(int u, vector<vector<int>> &adj, vector<int> &vis, int count)
{
    if (count == (int)vis.size())
        return true;
    for (int v : adj[u])
        if (!vis[v])
        {
            vis[v] = 1;
            if (backtrack(v, adj, vis, count + 1))
                return true;
            vis[v] = 0;
        }
    return false;
}

int bruteForce(vector<vector<int>> &adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        vector<int> vis(V, 0);
        vis[i] = 1;
        if (backtrack(i, adj, vis, 1))
            return 1;
    }
    return 0;
}

int optimal(vector<vector<int>> &adj)
{
    // no efficient poly solution; use same backtracking (exponential)
    return bruteForce(adj);
}

int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bruteForce(adj) << "\n";
    cout << optimal(adj) << "\n";
    return 0;
}
