#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int bruteForce(int V, vector<vector<int>> &adj)
{
    // brute: run DFS with stack and check back edges via adjacency matrix
    vector<vector<int>> mat(V, vector<int>(V, 0));
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            mat[u][v] = 1;
    vector<int> vis(V, 0), rec(V, 0);

    function<int(int)> dfs; // declare first
    dfs = [&](int u) -> int
    {
        vis[u] = 1;
        rec[u] = 1;
        for (int v = 0; v < V; v++) {
            if (mat[u][v]) {
                if (!vis[v]) {
                    if (dfs(v)) return 1;
                } else if (rec[v]) {
                    return 1;
                }
            }
        }
        rec[u] = 0;
        return 0;
    };

    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i))
                return 1;
    return 0;
}

int optimal(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V, 0), rec(V, 0);
    function<int(int)> dfs; // declare first
    dfs = [&](int u) -> int
    {
        vis[u] = 1;
        rec[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v)) return 1;
            } else if (rec[v]) {
                return 1;
            }
        }
        rec[u] = 0;
        return 0;
    };

    for (int i = 0; i < V; i++)
        if (!vis[i])
            if (dfs(i))
                return 1;
    return 0;
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
    }
    cout << bruteForce(V, adj) << "\n";
    cout << optimal(V, adj) << "\n";
    return 0;
}
