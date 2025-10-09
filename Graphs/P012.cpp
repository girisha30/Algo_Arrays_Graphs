#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bruteDfsMat(int u, vector<vector<int>> &mat, vector<int> &vis)
{
    vis[u] = 1;
    cout << u << " ";
    int V = mat.size();
    for (int v = 0; v < V; v++)
        if (mat[u][v] && !vis[v])
            bruteDfsMat(v, mat, vis);
}
void bruteForce(int V, vector<vector<int>> &adj, int start)
{
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            mat[u][v] = 1;
    vector<int> vis(V, 0);
    if (start >= 0 && start < V)
        bruteDfsMat(start, mat, vis);
    cout << "\n";
}

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    cout << u << " ";
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, adj, vis);
}
void optimal(int V, vector<vector<int>> &adj, int start)
{
    for (int i = 0; i < V; i++)
        sort(adj[i].begin(), adj[i].end());
    vector<int> vis(V, 0);
    if (start >= 0 && start < V)
        dfs(start, adj, vis);
    cout << "\n";
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
    int start;
    cin >> start;
    bruteForce(V, adj, start);
    optimal(V, adj, start);
}
