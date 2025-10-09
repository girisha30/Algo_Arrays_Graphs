#include <iostream>
#include <vector>
using namespace std;

bool bruteDfs(int u, int p, vector<vector<int>> &mat, vector<int> &vis)
{
    vis[u] = 1;
    int V = mat.size();
    for (int v = 0; v < V; v++)
    {
        if (mat[u][v])
        {
            if (!vis[v])
            {
                if (bruteDfs(v, u, mat, vis))
                    return true;
            }
            else if (v != p)
                return true;
        }
    }
    return false;
}
int bruteForce(int V, vector<vector<int>> &adj)
{
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            mat[u][v] = 1;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (bruteDfs(i, -1, mat, vis))
                return 1;
    return 0;
}

bool dfs(int u, int p, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            if (dfs(v, u, adj, vis))
                return true;
        }
        else if (v != p)
            return true;
    }
    return false;
}
int optimal(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i, -1, adj, vis))
                return 1;
    return 0;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bruteForce(V, adj) << "\n";
    cout << optimal(V, adj) << "\n";
}
