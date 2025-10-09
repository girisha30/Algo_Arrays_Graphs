#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, adj, vis);
}

vector<pair<int, int>> bruteForce(int V, vector<vector<int>> &adj)
{
    vector<pair<int, int>> bridges;
    // for each edge, remove and check connectivity increase
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            if (u < v)
            {
                // build new graph without u-v
                vector<vector<int>> g(V);
                for (int i = 0; i < V; i++)
                    for (int j : adj[i])
                        if (!(i == u && j == v) && !(i == v && j == u))
                            g[i].push_back(j);
                vector<int> vis(V, 0);
                // start DFS from node 0 (assumes nodes are 0..V-1)
                dfs(0, g, vis);
                bool connected = true;
                for (int i = 0; i < V; i++)
                    if (!vis[i])
                        connected = false;
                if (!connected)
                    bridges.push_back({u, v});
            }
    return bridges;
}

vector<pair<int, int>> optimal(int V, vector<vector<int>> &adj)
{
    vector<int> tin(V, -1), low(V, -1), vis(V, 0);
    int timer = 0;
    vector<pair<int, int>> bridges;

    // declare then assign so lambda can call itself
    function<void(int, int)> dfsTarjan;
    dfsTarjan = [&](int u, int p)
    {
        vis[u] = 1;
        tin[u] = low[u] = ++timer;
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            if (vis[v])
            {
                low[u] = min(low[u], tin[v]);
            }
            else
            {
                dfsTarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u])
                    bridges.push_back({u, v});
            }
        }
    };

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfsTarjan(i, -1);

    return bridges;
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
    auto b = bruteForce(V, adj);
    auto o = optimal(V, adj);
    for (auto &p : b)
        cout << p.first << " " << p.second << "\n";
    for (auto &p : o)
        cout << p.first << " " << p.second << "\n";
    return 0;
}
