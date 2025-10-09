#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>  // for reverse
#include <functional> // for greater<>
using namespace std;

vector<int> bruteForce(int V, vector<vector<pair<int, int>>> &adj, int src, int dest)
{
    const long long INF = 1LL << 60;
    vector<long long> dist(V, INF);
    vector<int> par(V, -1);
    dist[src] = 0;
    for (int it = 0; it < V; it++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (dist[i] < INF && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1)
            break;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    if (dist[dest] == INF)
        return vector<int>();
    vector<int> path;
    for (int v = dest; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> optimal(int V, vector<vector<pair<int, int>>> &adj, int src, int dest)
{
    const long long INF = 1LL << 60;
    vector<long long> dist(V, INF);
    vector<int> par(V, -1);
    // priority_queue with min-heap using greater<>
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        long long d = cur.first;
        int u = cur.second;
        if (d != dist[u])
            continue;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[dest] == INF)
        return vector<int>();
    vector<int> path;
    for (int v = dest; v != -1; v = par[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
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
    int src;
    cin >> src;
    int dest;
    cin >> dest;
    auto b = bruteForce(V, adj, src, dest);
    for (size_t i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 == b.size() ? "\n" : " ");
    auto o = optimal(V, adj, src, dest);
    for (size_t i = 0; i < o.size(); i++)
        cout << o[i] << (i + 1 == o.size() ? "\n" : " ");
    return 0;
}
