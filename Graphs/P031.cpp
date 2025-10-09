#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bruteForce(int V, vector<vector<pair<int, int>>> &adj)
{
    // Prim naive using vector search for min key (O(V^2))
    vector<int> key(V, 1e9), inMST(V, 0);
    key[0] = 0;
    int total = 0;
    for (int i = 0; i < V; i++)
    {
        int u = -1;
        for (int j = 0; j < V; j++)
            if (!inMST[j] && (u == -1 || key[j] < key[u]))
                u = j;
        inMST[u] = 1;
        total += key[u] == 1e9 ? 0 : key[u];
        for (auto &p : adj[u])
        {
            int v = p.first, w = p.second;
            if (!inMST[v] && w < key[v])
                key[v] = w;
        }
    }
    return total;
}

int optimal(int V, vector<vector<pair<int, int>>> &adj)
{
    // Prim with PQ
    vector<int> key(V, 1e9), inMST(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int u = cur.second, w = cur.first;
        if (inMST[u])
            continue;
        inMST[u] = 1;
        total += w;
        for (auto &p : adj[u])
        {
            int v = p.first, wt = p.second;
            if (!inMST[v] && wt < key[v])
            {
                key[v] = wt;
                pq.push({wt, v});
            }
        }
    }
    return total;
}

int main()
{
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << bruteForce(V, adj) << "\n";
    cout << optimal(V, adj) << "\n";
    return 0;
}
