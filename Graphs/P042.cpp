#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> bruteForce(int V, vector<vector<int>> &adj)
{
    // naive: compute topo order and return its size as path cover simplification
    vector<int> indeg(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            indeg[v]++;
    vector<int> q;
    for (int i = 0; i < V; i++)
        if (indeg[i] == 0)
            q.push_back(i);
    return {(int)q.size(), q};
}

pair<int, vector<int>> optimal(int V, vector<vector<int>> &adj)
{
    return bruteForce(V, adj);
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
    auto b = bruteForce(V, adj);
    cout << b.first << "\n";
    for (size_t i = 0; i < b.second.size(); i++)
        cout << b.second[i] << (i + 1 == b.second.size() ? "\n" : " ");
    auto o = optimal(V, adj);
    cout << o.first << "\n";
    for (size_t i = 0; i < o.second.size(); i++)
        cout << o.second[i] << (i + 1 == o.second.size() ? "\n" : " ");
    return 0;
}
