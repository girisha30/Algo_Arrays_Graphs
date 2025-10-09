#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<long long> bruteForce(int V, vector<vector<pair<int, int>>> &adj, int S)
{
    const long long INF = (1LL << 60);
    vector<long long> dist(V, INF);
    vector<int> used(V, 0);
    dist[S] = 0;
    for (int it = 0; it < V; it++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        if (u == -1 || dist[u] >= INF / 2)
            break;
        used[u] = 1;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    return dist;
}
vector<long long> optimal(int V, vector<vector<pair<int, int>>> &adj, int S)
{
    const long long INF = (1LL << 60);
    vector<long long> dist(V, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[S] = 0;
    pq.push({0, S});
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
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int S;
    cin >> S;
    auto a = bruteForce(V, adj, S), b = optimal(V, adj, S);
    for (int i = 0; i < V; i++)
        cout << (a[i] > (1LL << 50) ? -1 : a[i]) << (i + 1 == V ? '\n' : ' ');
    for (int i = 0; i < V; i++)
        cout << (b[i] > (1LL << 50) ? -1 : b[i]) << (i + 1 == V ? '\n' : ' ');
}
