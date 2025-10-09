#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

void dfsInt(int u, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v])
            dfsInt(v, adj, vis);
}

vector<int> bruteForce(int V, vector<vector<int>> &adj)
{
    vector<int> arts;
    for (int rem = 0; rem < V; rem++)
    {
        vector<int> vis(V, 0);
        vis[rem] = 1; // treat removed node as already visited

        // find a start node that is not removed
        int start = -1;
        for (int i = 0; i < V; ++i)
            if (!vis[i]) { start = i; break; }

        if (start == -1) {
            // no other nodes -> removing this node leaves graph empty, not articulation
            continue;
        }

        dfsInt(start, adj, vis);

        int cnt = 0;
        for (int i = 0; i < V; i++)
            if (!vis[i])
                cnt++;
        if (cnt > 0)
            arts.push_back(rem);
    }
    return arts;
}

vector<int> optimal(int V, vector<vector<int>> &adj)
{
    vector<int> tin(V, -1), low(V, -1), vis(V, 0), isArt(V, 0);
    int timer = 0;

    function<void(int,int)> dfs; // declare first
    dfs = [&](int u, int p)
    {
        vis[u] = 1;
        tin[u] = low[u] = ++timer;
        int children = 0;
        for (int v : adj[u])
        {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                children++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u] && p != -1) isArt[u] = 1;
            }
        }
        if (p == -1 && children > 1) isArt[u] = 1;
    };

    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i, -1);

    vector<int> res;
    for (int i = 0; i < V; i++)
        if (isArt[i])
            res.push_back(i);
    return res;
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
    for (size_t i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 == b.size() ? "\n" : " ");
    for (size_t i = 0; i < o.size(); i++)
        cout << o[i] << (i + 1 == o.size() ? "\n" : " ");
    return 0;
}
